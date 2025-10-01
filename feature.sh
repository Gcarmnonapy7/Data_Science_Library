#!/bin/bash

set -e

BRANCH_NAME=$1
COMMIT_MESSAGE=$2

if [ -z "$BRANCH_NAME" ] || [ -z "$COMMIT_MESSAGE" ]; then
    echo "Branch name and commit message are required."
    exit 1
fi

echo "Creating and pushing to branch: $BRANCH_NAME with commit message: $COMMIT_MESSAGE"
git checkout -b feature/${BRANCH_NAME} 
    
echo "Adding all changes in the new branch"
git add .

echo "Committing changes with message: $COMMIT_MESSAGE"
git commit -m "$COMMIT_MESSAGE"
    
echo "Pushing changes to remote repository (Check the pull request)"
git push -u origin feature/${BRANCH_NAME} 
