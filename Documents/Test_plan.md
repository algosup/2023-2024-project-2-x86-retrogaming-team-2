## Test Plan


| Author        | Gaël MALVAR |
|---------------|------------ |
| Created       | 11/17/2023  |
| Last Modified | 12/07/2023  |

---

<details>

<summary>📖 Table of content</summary>

- [Test Plan](#test-plan)
  - [Glossary](#glossary)
  - [Testing strategy](#testing-strategy)
    - [Smoke test](#smoke-test)
    - [Functionality Test](#functionality-test)
    - [Compatibility Testing](#compatibility-testing)
    - [Performance Testing](#performance-testing)
  - [Schedule](#schedule)
  - [Test Cases](#test-cases)
  - [Testing tools](#testing-tools)
    - [Hardware](#hardware)
    - [Software](#software)
  - [Issues Report](#issues-report)


</details>

---

This is the test plan for our version of Pac-Man coded in x86 assembly.

The purpose of these tests is to verify that the game works as expected and is playable. We'll detail how we'll test the game, what type of testing we'll do, and how we'll ensure the game works in the end.

---

### Glossary

| Term | Definition |
|---|---|
| Smoke test | A smoke test is a quick and basic check or test performed to verify that it works on a fundamental level. A smoke test ensures that the main functionalities of a program or system are operational without delving into detailed or exhaustive testing. |
| Functional test | Functional testing is a process categorized as black-box testing. It constructs test cases based on the specified requirements of the software component under examination. |
| Regression test | A regression test is a check to ensure that recent changes to a software application haven't negatively impacted its existing functionalities. It helps catch unintended side effects or "regressions" that might occur when new features or updates are added. |
| Test case | A "test case" is a specific set of instructions or conditions that are designed to determine whether a software application, system, or component functions correctly under certain circumstances. It's a detailed scenario or situation used to verify that the software behaves as expected. |

---

### Testing strategy

The strategy that will be used to test the game is to test it manually. The tester will have to test the game throughout the development phase and also afterwards in order to prevent the appearance of bugs and to be able to resolve them if there are any.

First, we'll run a smoke test to see if the basic functionality works. When the smoke test is successful, we will then perform a functional test to ensure all features work as expected. Then we will do a regression test after each new version to see if any new bugs appear.

---

#### Smoke test

This is a short description of the somke test we will perform

1.  **Start the game** 
2.  **Exit the game** 
3.  **Movements** 
4.  **Collision**

The purpose of these tests is to verify and confirm that the main features of our game work well.

#### Functionality Test

| Name of the test | Description |
| --- | --- |
| Maze Navigation | Verify that the player can navigate the maze, be able to use the tunnels, consume pellets, and escape from enemies. |
| Foes Behavior | Ensure that the behavior of the foes works as expected for each of them. |
| Game Levels | Check if the game progresses through levels correctly. The game should change level when the player eats all the dots. |
| Win | The game should end when the player wins all levels. |
| Lose | The game should end when the player loses all lives. |
| Live | The number of lives should decrease when the player is eaten. |
| Score | The score should increase when the player eats a dot, a pellet, or an enemy. |


#### Compatibility Testing

| Test | Description |
| --- | --- |
|Cross-platform compatibility | Test the game on various platforms and devices and ensure that the game is responsive. |
| Peripheral devices | Test the game with different peripherals such as keyboards and controllers. |


####  Performance Testing

| Test | Description |
| --- | --- |
| Movement and Controls | Test the responsiveness and accuracy of player movement controls. |
| Load Testing | Evaluate the time it takes for the game to initially load as well as the loading time between levels to ensure a smooth experience. |
| Stress Testing | Push the game to its limits to identify any breaking points, such as excessive collisions or power-ups. |

---

### Schedule

_We do not yet have a playable version of the game and therefore cannot yet plan a schedule_

---

### Test Cases

During the testing phase, all the tests carried out will be stored in the “TestCases.md” file.

**Here is an example of a test case :**

| Test Case ID | 1 |
| --- | --- |
| Name | Name of the test |
| Description | Description of what should happen |
| Pre-conditions | What conditions must be met before starting the test |
| Steps | Step taken to obtain the expected result |
| Expected Result | Expected result after the test |
| Actual Result | Actual result after test |
| Status | Test status (To test, In testing, Tested) |
| Priority | The priority of the test (High, Medium, Low) |

---

### Testing tools

In order to test the game, we will use several tools.

#### Hardware

We will run and test the game on different machines, we have 2 at our disposal : 

Lenovo ThinkBook :
  - ThinkBook 14 G4 IAP
    - **Processor** : 12th Gen Intel(R) Core(TM) i7-1255U   1.70 GHz
    - **RAM** : 16.0 GB
    - **System** : 64-bit operating system, x64-based processor
    - **Operating system** : Windows 11 Pro ( Version : 22H2 ) 
  
MacBook Air : 
  - MacBook Air 13″
    - **Processor** : Apple M1 chip
    - **RAM** : 8.0 GB
    - **Operating system** : macOS Ventura



#### Software

We will use different software to run the game, test it, report different bugs and resolve them.

- **DOSBox** to run the game and test it on our different Hardware.
  - DOSBox **0.74-3** for Windows
  - DOSBox **0.74-3** for macOS
- **NASM** to compile the assembly language.
- **GitHub** to report bugs.
- **Visual Studio Code** ( version 1.84.2 ) to develop the game and fix bugs.

---

### Issues Report

**Issue n°X**

**Date**

MM/DD/YYYY

**Description :**

**Actions performed :**

Actions performed to reproduce the bug

**Expected result :**

What should happen when the program works as expected

**Actual result :**

What actually happened

**Screenshot :**

(if it gives additional informations)