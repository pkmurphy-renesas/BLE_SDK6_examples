"""This script checks the output of the build process."""
import json
import os
import shutil

from common import Project, Target, bashexec

if __name__ == "__main__":
    # set variables
    targets = []
    workdir = os.getenv("GITHUB_WORKSPACE", os.getcwd())
    artifactsdir = workdir + "/artifacts"
    targetsfile = workdir + "/.github/config/targets.json"
    buildlistfile = workdir + "/.github/config/build-list.txt"

    # read intended targets
    f = open(targetsfile)
    targetsData = json.load(f)
    for tD in targetsData:
        targets.append(Target(tD["name"], tD["acronym"]))

    # read buildlist
    with open(buildlistfile) as f:
        exlist = f.read().splitlines()

    # scan build outputs for passed builds
    for d in exlist:
        exfolder = bashexec("dirname " + d)[0].decode("utf-8").rstrip()
        exname = bashexec("basename " + exfolder)[0].decode("utf-8").rstrip()
        for t in targets:
            if (
                bashexec(
                    [
                        "grep",
                        "-q",
                        "set(BUILD_FOR_" + t.acronym + " TRUE)",
                        workdir + "/" + exfolder + "/CMakeLists.txt",
                    ]
                )[1]
                == 0
            ):
                if (
                    bashexec(
                        "test -f "
                        + exfolder
                        + "/build/"
                        + exname
                        + "_"
                        + t.acronym
                        + ".elf"
                    )[1]
                    == 0
                ):
                    t.passed.append(Project(exfolder))
                else:
                    t.failed.append(Project(exfolder))

    # print output
    for t in targets:
        print("\npassed " + t.name + ":")
        for p in t.passed:
            print(p.path)
        print("\nfailed " + t.name + ":")
        for f in t.failed:
            print(f.path)
        print("\n---------------")
        print("| PASSED: " + str(len(t.passed)) + " ")
        print("| FAILED: " + str(len(t.failed)) + " ")
        print("---------------")

    # produce meta data (projectData.json)
    if os.path.exists(artifactsdir):
        shutil.rmtree(artifactsdir)
    os.mkdir(artifactsdir, mode=0o777)
    for t in targets:
        for p in t.passed:
            t.metadata.append(p.toDict())
        os.mkdir(artifactsdir + "/" + t.name)
        with open(artifactsdir + "/" + t.name + "/projectData.json", "w") as output:
            output.write(json.dumps({"examples": t.metadata}, indent=3))
