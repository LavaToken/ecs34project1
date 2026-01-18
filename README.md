# Project X README

Student 1: Partner1 Name (123456789)

Student 2: Partner2 Name (123456987)

## Project Status
Project is complete

## Known Issues
I spent so long trying to set empty char parameters to ' ' only to realize they were defaulted in StringUtils.h (´；ω；`)
Additionally, C++ as a language was a bit of a hassle for me. My primary language is Java and I haven't used C++ since Fall 2024(ECS32C because I was unable to get off the waitlist for ECS34 that year) so some syntax confused me.

## Code References
* [Different ways to initialize variables](https://stackoverflow.com/questions/22543875/different-ways-to-initialize-variables)
* [C++ References](https://cplusplus.com/reference/)
* [Levenshtein Distance(Provided by instructor in project file)](https://en.wikipedia.org/wiki/Levenshtein_distance)
* [2D Vectors in C++](https://www.geeksforgeeks.org/cpp/2d-vector-in-cpp-with-user-defined-size/)

## Generative AI Use
I used ChatGPT to help me setup Docker. It took a very long time until I realized that the most recent version of Docker was not compatible with my MacOS, so I downloaded an older version for support.

### Prompt 1
"You can’t use this version of the application “Docker” with this version of macOS."(error prompt)

### Response 1
That message means your macOS is too old for the Docker Desktop build you installed.

Docker’s official policy is: Docker Desktop supports the current macOS major release + the previous two (and drops the oldest when a new macOS comes out).

So you have 3 realistic options:

Option A (best): Update macOS to a supported version

If your Mac supports a newer macOS, updating will let you install the latest Docker Desktop cleanly.

 → System Settings → General → Software Update

Update to the newest macOS your Mac supports

Re-download Docker Desktop from Docker’s official page

Option B: Install an older Docker Desktop that matches your macOS

If you can’t update macOS, you need an older Docker Desktop version that still supports your version.

For example, for macOS 11 Big Sur, people commonly report that Docker Desktop 4.22.0 is the last officially supported version, and newer versions require macOS 12 Monterey+.

How to get older versions:

Docker’s Release Notes page is the official place to find older installers.

Option C: Skip Docker Desktop and use an alternative (works great on older macOS)

If you’re stuck on an older macOS and Docker Desktop options are painful, use:

Colima (lightweight Docker runtime using Lima)

Rancher Desktop

Podman Desktop

(These can run containers without needing the newest Docker Desktop.)

Fast way to pinpoint the correct fix

On your Mac, click  → About This Mac and tell me:

your macOS version number (e.g., 10.15.x, 11.x, 12.x)

whether your Mac is Intel or Apple Silicon (M1/M2/M3)

Then I’ll tell you the exact Docker Desktop version you should install (or the best alternative if you’re too far back).

### Changes 1
I chose Option B and downloaded an older version of Docker, I did not want to update my MacOS because I did not want the new OS to use more of my computer's limited resources, especially when I rely on heavy processing tasks like Adobe Lightroom.

### Prompt 2
My other prompt...

### Response 2
The other response...

### Changes 2
The other changes made...
