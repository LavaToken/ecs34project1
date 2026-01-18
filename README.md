# Project 1 README

Student 1: Kevin Jia (921898728)

## Project Status
Project should be complete

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

I also used ChatGPT to convert functions I knew syntactically in Java, but not C++.

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
what is the c++ equivalent to the java function str.substring(i, i+x)

### Response 2
The direct C++ equivalent of Java’s:

str.substring(i, i + x)


is:

str.substr(i, x)

Why this matches exactly
Java	C++
substring(begin, end)	substr(start, length)
end index is exclusive	length is count of chars

So:

str.substring(i, i + x)


→ take x characters starting at index i

str.substr(i, x)


→ take x characters starting at index i

Important details (corner cases)
1️⃣ Bounds behavior difference

Java

str.substring(i, i + x);  // throws IndexOutOfBoundsException if invalid


C++

str.substr(i, x);         // throws std::out_of_range ONLY if i > size()
                          // x can exceed size; it just clamps


Example:

std::string s = "hello";
s.substr(2, 100);  // "llo" (no crash)

2️⃣ Empty substring
str.substring(3, 3);  // ""

str.substr(3, 0);     // ""

3️⃣ i == length
str.substring(len, len);  // ""

str.substr(len, 0);       // ""

4️⃣ i > length (danger)
str.substr(len + 1, x);   // throws std::out_of_range


So always guard:

if (i <= str.size()) {
    str.substr(i, x);
}

Quick reference (memorize)
// Java
str.substring(start, end);

// C++
str.substr(start, end - start);
// or if end = start + x:
str.substr(start, x);

TL;DR (exam gold)

Java substring(start, end) ≡ C++ substr(start, end-start)

If you want, I can:

show how to translate Java substring-heavy code safely to C++

help you avoid the segfault traps that come from this difference

### Changes 2
Added to code

### Prompt 3
what is the c++ equivalent to the java function int[][] matrix = new int[x][y]

### Response 3
The direct, idiomatic C++ equivalent of Java’s:

int[][] matrix = new int[x][y];


depends on whether x and y are known at compile time or runtime.

Below are the correct C++ equivalents, from safest → lowest-level.

✅ Best & safest (recommended): std::vector
Java
int[][] matrix = new int[x][y];

C++
std::vector<std::vector<int>> matrix(x, std::vector<int>(y));

Why this matches Java semantics

Dynamic size

Zero-initialized

Bounds-safe with .at()

Automatically freed

No memory leaks

This is what almost all modern C++ code uses.

⚠️ Lower-level (manual allocation, Java-like but dangerous)
C++
int** matrix = new int*[x];
for (int i = 0; i < x; ++i) {
    matrix[i] = new int[y]();
}


And later:

for (int i = 0; i < x; ++i) {
    delete[] matrix[i];
}
delete[] matrix;


❌ Easy to leak
❌ No bounds checking
❌ Avoid unless required by assignment

⚠️ Stack allocation (ONLY if sizes are compile-time constants)
int matrix[X][Y];


This is not equivalent to Java’s dynamic allocation.

🚀 Fast contiguous 2D array (advanced)
std::vector<int> matrix(x * y);
auto at = [&](int i, int j) -> int& {
    return matrix[i * y + j];
};


Use this if:

performance matters

cache locality matters

large matrices

Comparison table (exam-ready)
Java	C++ equivalent
new int[x][y]	vector<vector<int>>
auto-zeroed	auto-zeroed
garbage collected	RAII
bounds checked	.at() optional
rectangular	rectangular
Which should YOU use?

If you’re coming from Java and implementing edit distance or similar DP:

std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));


This is the correct and expected answer.

TL;DR

Java new int[x][y] ≡ C++ std::vector<std::vector<int>> matrix(x, std::vector<int>(y));

If you want, I can:

Convert your Java Levenshtein DP line-for-line to C++

Show how to optimize memory to O(min(m,n))

Explain why int[][] in Java isn’t truly contiguous either


### Change 3
Converted int[][] from Java to std::vector<std::vector<size_t>> matrix(x, std::vector<size_t>(y)).
