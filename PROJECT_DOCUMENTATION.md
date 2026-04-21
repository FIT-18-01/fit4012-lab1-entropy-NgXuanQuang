# FIT4012 Lab 1 – Project Documentation

## Overview

This is a **C++ project** that implements three core concepts from information theory and modular arithmetic:

1. **Entropy** calculation for string analysis
2. **Redundancy** measurement based on entropy
3. **Modular Inverse** computation using Extended Euclidean Algorithm

---

## Configuration Files Analysis

### 1. **check_lab01.py** (.github/scripts/)

**Purpose**: Automated validation script that checks if the lab submission meets all requirements.

**Key Validations**:

- ✅ Verifies all required files exist
- ✅ Checks that `TODO(student)` placeholders are removed
- ✅ Validates that `calculate_redundancy()` is implemented (not returning -1.0)
- ✅ Validates that `mod_inverse()` is implemented (not returning -1)
- ✅ Confirms at least 5 test cases are marked as completed
- ✅ Confirms at least 5 log entries are marked as completed
- ✅ Verifies README contains keywords: entropy, redundancy, modulo, GitHub
- ✅ Checks that entropy/redundancy results table is filled
- ✅ Compiles both .cpp files with g++ compiler
- ✅ Confirms at least 3 commits in git history

---

### 2. **classroom.yml** (.github/workflows/)

**Purpose**: GitHub Actions workflow for **GitHub Classroom** autograding integration.

**Workflow Details**:

- **Trigger**: Runs on every push and repository dispatch event
- **Runner**: Latest Ubuntu environment
- **Exclusion**: Skips when `github-classroom[bot]` makes changes
- **Test Command**: Executes `python3 .github/scripts/check_lab01.py`
- **Timeout**: 10 seconds max
- **Max Score**: 10 points
- **Output**: Reports results via GitHub's autograding grading reporter

**Status**: This is the **primary grading workflow** used by GitHub Classroom.

---

### 3. **lab01-check.yml** (.github/workflows/)

**Purpose**: Alternative CI/CD workflow for **manual testing and verification**.

**Workflow Details**:

- **Trigger**:
  - Runs on push to `main` or `master` branches
  - Runs on pull requests to `main` or `master`
  - Can be manually triggered via `workflow_dispatch`
- **Runner**: Latest Ubuntu environment
- **Setup Steps**:
  - Checks out repository with full history (`fetch-depth: 0`)
  - Sets up Python 3.11
  - Installs g++ compiler via apt-get
- **Validation**: Runs the same checker script as classroom.yml
- **Status**: Provides additional validation layer for development

---

## Project File Structure & Requirements

### Required Files Checklist

#### **README.md** ✅

- Lab objectives and description
- Repository structure explanation
- Submission requirements
- Suggested commit messages
- **Keywords**: entropy, redundancy, modulo, GitHub (required for passing)

#### **src/entropy_redundancy.cpp** ✅

- Implements `calculate_entropy(string data)`: Uses frequency analysis and Shannon entropy formula
- Implements `calculate_redundancy(double entropy, int alphabet_size)`: Calculates R = 1 - H/H_max
- Main function tests with: "aaaa", "abcd", "hello world"
- **No TODO(student)** markers allowed
- **Must not** return -1.0 from redundancy calculation

#### **src/mod_inverse.cpp** ✅

- Implements `extended_gcd(int a, int b, int &x, int &y)`: Extended Euclidean Algorithm
- Implements `mod_inverse(int a, int m)`: Finds x where (a × x) ≡ 1 (mod m)
- Returns -1 if inverse doesn't exist (when gcd(a,m) ≠ 1)
- Main function tests with: (3,7), (10,17), (6,9)
- **No TODO(student)** markers allowed

#### **tests/test_cases.md** ✅

- Minimum 5 test cases with [x] checkmarks for entropy/redundancy
- Minimum 5 test cases with [x] checkmarks for modular inverse
- Includes expected outputs and test descriptions
- **Requirement**: At least 5 completed items marked

#### **logs/run_log.md** ✅

- Minimum 5 completed execution logs for entropy tests
- Minimum 5 completed execution logs for modular inverse tests
- Summary section "Điều em học được từ bài lab" (What I learned)
- **Requirement**: At least 5 completed items marked

#### **report-page.md** ✅

- **Section 1**: Lab objectives
- **Section 2**: Methodology explanation
- **Section 3**: Results with filled entropy/redundancy table
- **Section 4**: Conclusion and lessons learned
- **Important**: Table must NOT contain placeholder like "| aaaa | | | |"

---

## Build & Verification Commands

```bash
# Compile entropy/redundancy program
g++ -std=c++17 -O2 -Wall -Wextra -pedantic src/entropy_redundancy.cpp -o entropy_app

# Compile modular inverse program
g++ -std=c++17 -O2 -Wall -Wextra -pedantic src/mod_inverse.cpp -o modinv_app

# Run validation script
python3 .github/scripts/check_lab01.py
```

---

## Project Status Summary

| Component              | Status      | Notes                             |
| ---------------------- | ----------- | --------------------------------- |
| README.md              | ✅ Complete | Contains required keywords        |
| entropy_redundancy.cpp | ✅ Complete | Fully implemented                 |
| mod_inverse.cpp        | ✅ Complete | Fully implemented                 |
| test_cases.md          | ✅ Complete | 5+ test cases marked              |
| run_log.md             | ✅ Complete | 5+ runs logged + summary          |
| report-page.md         | ✅ Complete | All sections filled               |
| Git Commits            | ✅ Complete | Multiple commits present          |
| Compilation            | ✅ Pass     | Both files compile without errors |

---

## Submission Checklist

- [x] All required files exist
- [x] No TODO(student) placeholders remain
- [x] Both .cpp files compile successfully
- [x] At least 5 test cases completed and checked
- [x] At least 5 log entries completed and checked
- [x] README contains entropy, redundancy, modulo, GitHub keywords
- [x] Report table with results is filled
- [x] Summary section in logs is complete
- [x] At least 3 meaningful commits
- [x] Project ready for GitHub Classroom submission

---

## How Grading Works

1. **GitHub Classroom** receives your submission push
2. **classroom.yml** workflow triggers automatically
3. Runs **check_lab01.py** validator script
4. Script checks all requirements above
5. Reports pass/fail with up to 10 points
6. Results visible in GitHub Classroom feedback

**Pass Condition**: All errors must be resolved; warnings don't block submission but should be addressed.
