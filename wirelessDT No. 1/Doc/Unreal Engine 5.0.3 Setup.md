# Unreal Engine 5.0.3 Setup

## Install

### STEP 0: Associate the GitHub account with UE account
Make sure you already have a GitHub account and have linked your GitHub account to your Unreal Engine account. If not, refer to the official tutorial.
[How do I link my Unreal Engine account with my Github account?](https://www.epicgames.com/help/en-US/epic-accounts-c5719348850459/connect-accounts-c5719351300507/how-do-i-link-my-unreal-engine-account-with-my-github-account-a5720369784347)

How to confirm whether the account is correctly linked you can check from the Application to account, as shown below:
![Connect the account](./fig/Connecttheaccount.png)

### Note：
After completing the associated account, there will be an invitation confirmation in the email, please check.


### STEP 1: Clone WiTracing Unreal Engine Project.
After associating the accounts, we should have access to our [Unreal Engine Fork](https://github.com/codelzz/UnrealEngine/tree/dev/ue5-witracing) with our built-in WiTracing Engine. Then you can clone the engine code from dev/ue5-witracing branch.
### Note:
1. This step requires the developer's permission to accept, you need the developer to invite your email into the group, otherwise you will see a 404 page.

2. If you suffered from the issue that shows the prohibition for using **setup.bat** as version issule for compiling,
Please copy the **Commit.gitdeps.xml** file in the folder **files** to overwirte the file in the director where you install the UnrealEngine Locally like below
"/UnrealEngine/Engine/Build/Commit.gitdeps.xml"
![DebugUnrealEngineXML](./fig/BuildDebugXML.png "Debug Unreal Engine XML")
