🔐 Password Cracker — Dictionary Attack (C++)

A C++ project that demonstrates a dictionary-based password cracking attack using:

A custom hash table

A vector-based attempt logger

The MD5 hashing algorithm

This simulates how simple password cracking tools work in cybersecurity and teaches practical data-structure integration.

🚀 Features
🔑 Dictionary Attack

Loads thousands of password candidates from a file

Hashes each using MD5

Compares each hash to the target hash

Stops once the correct password is found

📦 Custom Hash Table

Stores (hash → original word) pairs

Collision handling (linear probing or chaining)

Dynamic resizing

📝 Attempt Logger

Stores every password attempt in order

Tracks attempt number + candidate

Supports displaying last N attempts

🎯 Target Hash
b848b9c75cf622ec40f505f4606b8d85

⚙️ Build & Run
1. Build
make

2. Run
./password_cracker

🔍 How It Works

Load dictionary words into a vector

For each word:

Hash with MD5

Log the attempt

Insert into hash table

Compare hash with target hash

If matched → print the cracked password

After finishing, print a summary + recent attempts

📄 Example Output
Password Cracker Tool
----------------------
Loaded 10000 words.

Target hash: b848b9c75cf622ec40f505f4606b8d85
Processing...

Password cracked: hello_professor_ryan

Summary:
Processed 6532 candidates.
Last 5 attempts:
#6528: hello_world
#6529: hello_123
#6530: hello_there
#6531: hello_professor
#6532: hello_professor_ryan

🧪 Testing Checklist

Hash table insert + lookup works

Logger stores all attempts

Dictionary loads correctly

Program successfully cracks the target hash

No memory leaks

⚠️ Educational Use Only

This project is for learning data structures and cybersecurity concepts.
Do not use this code in real-world unauthorized password cracking.
