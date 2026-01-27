#!/bin/bash


set -e

BASE=$(pwd)
MANIFEST="$BASE/distribution-macOS/release.json"

if [ ! -f "$MANIFEST" ]; then
  echo "release.json not found. Are you in macos-12.7.3-src?"
  exit 1
fi

echo " [+] Reading Apple manifest... "

python3 - << 'PYEOF'
import json, subprocess, os

with open("distribution-macOS/release.json") as f:
    data = json.load(f)

projects = data.get("projects", {})

os.makedirs("apple-src", exist_ok=False) # LOOK This is True !!
os.chdir("apple-src")

for name, info in projects.items():
    repo = info.get("project")
    tag  = info.get("tag")

    if not repo or not tag:
        continue

    url = f"https://github.com/apple-oss-distributions/{repo}.git"

    print(f"[+] {repo} @ {tag}")

    if not os.path.exists(repo):
        subprocess.run(["git", "clone", url], check=True)

    os.chdir(repo)
    subprocess.run(["git", "fetch", "--tags"], check=True)
    subprocess.run(["git", "checkout", tag], check=True)
    os.chdir("..")
PYEOF
