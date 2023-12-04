## Test Plan

---

<details>

<summary>📖 Table of content</summary>

- [Test Plan](#test-plan)
  - [Strategy](#strategy)
    - [Functionality Test](#functionality-test)
    - [Compatibility Testing](#compatibility-testing)
    - [Performance Testing](#performance-testing)
  - [Schedule](#schedule)
  - [Tools](#tools)
    - [Hardware](#hardware)
    - [Software](#software)
  - [Issues Report](#issues-report)


</details>

---

This is the test plan for our version of Pac-Man.

The purpose of these tests is to verify that the game works as expected and is playable.

---

### Strategy

The strategy that will be used to test the game is to test it manually. The tester will have to test the game throughout the development phase and also afterwards in order to prevent the appearance of bugs and to be able to resolve them if there are any.


#### Functionality Test

| Name of the test | Description |
| --- | --- |
| Movement and Controls | Test if the controls are working properly. |
| Foes Behavior | Ensure that the behavior of the foes works as expected for each of them. |
| Maze Navigation | Verify that the player can navigate the maze, consume pellets, and escape from enemies. |
| Collision | The player should not be able to walk through walls. |
| Game Levels | Check if the game progresses through levels correctly. The game should change level when the player eats all the dots. |
| Exit | The game should exit when the user clicks on the exit button. |
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

### Tools

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
    - **Apple M1** chip
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
