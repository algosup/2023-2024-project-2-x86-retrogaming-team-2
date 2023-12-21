# Test Cases

---

In this document we will describe the tests that we will perform and the results obtained

---

### Legend : 
- **Status** : To test ⏳, In testing 🚧, Tested ✅
- **Priority** : High 🔴, Medium 🟡, Low 🔵



## Test Case 1 :    

| Test Case ID | 1 |
| --- | --- |
| Name | Start the game |
| Description | The game starts when the user presses the start button |
| Pre-conditions | The game hasn't started yet |
| Steps | 1. Click on the start button |
| Expected Result | The game starts |
| Actual Result | ------ |
| Status | To test ⏳ |
| Priority | High 🔴 |

## Test Case 2 :

| Test Case ID | 2 |
| --- | --- |
| Name | Exit the game |
| Description | The game ends when the user presses the button  |
| Pre-conditions | The game has started |
| Steps | 1. Click on the exit button |
| Expected Result | The game ends |
| Actual Result | ------ |
| Status | To test ⏳ |
| Priority | High 🔴 |

## Test Case 3 :

| Test Case ID | 3 |
| --- | --- |
| Name | Move left |
| Description | The player can move to the left  |
| Pre-conditions | The game has started |
| Steps | 1. Press the Q key or left arrow key |
| Expected Result | The player moves to the left |
| Actual Result | When the Q key or left arrow key is pressed, the player moves left |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 4 :

| Test Case ID | 4 |
| --- | --- |
| Name | Move right |
| Description | The player can move to the right |
| Pre-conditions | The game has started |
| Steps | 1. Press the D key or right arrow key |
| Expected Result | The player moves to the right |
| Actual Result | When the D key or right arrow key is pressed, the player moves right |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 5 :

| Test Case ID | 5 |
| --- | --- |
| Name | Move up |
| Description | The player can moves upwards |
| Pre-conditions | The game has started |
| Steps | 1. Press the Z key or up arrow key |
| Expected Result | The player moves upwards |
| Actual Result | When the Z key or up arrow key is pressed, the player moves upwards |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 6 :

| Test Case ID | 6 |
| --- | --- |
| Name | Move down |
| Description | The player can move down |
| Pre-conditions | The game has started |
| Steps | 1. Press the S key or down arrow key |
| Expected Result | The player moves down |
| Actual Result | When the S key or down arrow key is pressed, the player moves down |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 7 :

| Test Case ID | 7 |
| --- | --- |
| Name | Wall collision |
| Description | The player and enemies should not be able to pass through walls |
| Pre-conditions | The game has started |
| Steps | 1. Move the player and enemies toward a wall |
| Expected Result | The player and enemies are not able to pass through the wall |
| Actual Result | Player and enemies cannot pass through walls |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 8 :

| Test Case ID | 8 |
| --- | --- |
| Name | Collision between player and enemies |
| Description | The player should not be able to pass through enemies |
| Pre-conditions | The game has started |
| Steps | 1. Move the player toward an enemy |
| Expected Result | The player stops against the enemy and dies |
| Actual Result | The player stops against the enemy and dies |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 9 :

| Test Case ID | 9 |
| --- | --- |
| Name | Collision between enemies |
| Description | Enemies should be able to cross each other |
| Pre-conditions | The game has started |
| Steps | 1. Wait till two enemies cross each other |
| Expected Result | Enemies cross each other |
| Actual Result | ------ |
| Status | To test ⏳ |
| Priority | Medium 🟡 |

## Test Case 10 :

| Test Case ID | 10 |
| --- | --- |
| Name | Tunnel |
| Description | The player should be able to use tunnels |
| Pre-conditions | The game has started |
| Steps | 1. Move the player into a tunnel |
| Expected Result | The player is teleported to the other side of the tunnel |
| Actual Result | The player can successfully enter the tunnels and be teleported to the other side |
| Status | Tested ✅ |
| Priority | Medium 🟡 |

## Test Case 11:

| Test Case ID | 11 |
| --- | --- |
| Name | Consume dots |
| Description | The player should be able to eat dots |
| Pre-conditions | The game has started |
| Steps | 1. Move the player toward a dot |
| Expected Result | The dot disappears and the score increase |
| Actual Result | The dot disappears and the score increase |
| Status | Tested ✅ |
| Priority | Medium 🟡 |

## Test Case 12 :

| Test Case ID | 12 |
| --- | --- |
| Name | Consume power pellets |
| Description | The player should be able to eat power pellets |
| Pre-conditions | The game has started |
| Steps | 1. Move the player toward a power pellet |
| Expected Result | The power pellet disappears and enemies become vulnerable to the player |
| Actual Result | The power pellet disappears and enemies become vulnerable to the player |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 13 :

| Test Case ID | 13 |
| --- | --- |
| Name | Eat enemies |
| Description | The player should be able to eat enemies |
| Pre-conditions | The game has started |
| Steps | 1. Move the player with the effect of a power pellet towards an enemy |
| Expected Result | The enemy is eaten and returns to its spawn point |
| Actual Result | The enemy is eaten and returns to its spawn point |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 14 :

| Test Case ID | 14 |
| --- | --- |
| Name | Score |
| Description | The score should increase when the player eat a dot, a power pellet or an enemy |
| Pre-conditions | The game has started |
| Steps | 1. Eat a dot, a power pellet and an enemy |
| Expected Result | The score increases accordingly on what was eaten |
| Actual Result | The score increases accordingly on what was eaten |
| Status | Tested ✅ |
| Priority | Medium 🟡 |

## Test Case 15 :

| Test Case ID | 15 |
| --- | --- |
| Name | Decrease lives |
| Description | The player should lose a life when eaten by an enemy |
| Pre-conditions | The game has started |
| Steps | 1. Let the enemy eat the player |
| Expected Result | The player loses a life and returns to the spawn point |
| Actual Result | The player loses a life and returns to the spawn point |
| Status | Tested ✅ |
| Priority | Medium 🟡 |

## Test Case 16 :

| Test Case ID | 16 |
| --- | --- |
| Name | Increase lives |
| Description | The player should gain a life when reaching a score of 10k points |
| Pre-conditions | The game has started |
| Steps | 1. Reach a score of 10k points |
| Expected Result | The player gains a life |
| Actual Result | ------ |
| Status | To test ⏳ |
| Priority | Medium 🟡 |

## Test Case 17 :

| Test Case ID | 17 |
| --- | --- |
| Name | Game over |
| Description | The player loses when he has lost all his lives  |
| Pre-conditions | The game has started |
| Steps | 1. Lose all lives |
| Expected Result | The player loses and a game over screen is displayed |
| Actual Result | The player loses and a game over screen is displayed |
| Status | Tested ✅ |
| Priority | High 🔴 |

## Test Case 18 :

| Test Case ID | 18 |
| --- | --- |
| Name | Win |
| Description | Player wins when all levels are completed |
| Pre-conditions | The game has started |
| Steps | 1. Complete all levels |
| Expected Result | The game should end when the player wins all levels |
| Actual Result | ------ |
| Status | To test ⏳ |
| Priority | Low 🔵 |

## Test Case 19 :

| Test Case ID | 19 |
| --- | --- |
| Name | Levels |
| Description | The game should move to the next level when all points are eaten |
| Pre-conditions | The game has started |
| Steps | 1. Eat all dots and pellets |
| Expected Result | The game goes to the next level |
| Actual Result | The game goes to the next level |
| Status | Tested ✅ |
| Priority | Medium 🟡 |