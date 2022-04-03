---
# SoCraps🎲
A simple craps style game written in C++/Qt.

Work in progress to help me learn. Used Qt 5.12.8 to build the Ui. The game is modeled off casino craps. Currently there is functional pass and don't pass line bets with point, place bets and onetime bets, repeat last bet buttons. A 7 rolled clears the table. 

🎲Deposit your play funds and roll the dice🎲

---
## Screenshot

![SoCrapsScreen](https://user-images.githubusercontent.com/84689659/161405837-fdc58e5f-cbb9-4391-91a9-c5d71fa367ac.jpg)
---
### To Do List
- [ ] Add pass & don't pass odds bets, *3-4-5 game*
- [ ] Add multi outcome bets ie: *any crap, horn, hi lo, field*
- [ ] Clean stuff up, might have some redundancies
- [X] Add pop up at the start with *how to play and rules* 
- [ ] Fix maximize to make full screen 
- [ ] Button colors don't work when built
- [ ] Further intergrations

---
## Build instructions
> ### With Qt Creator
1. Download and install Qt Creator (https://www.qt.io/download-open-source/)
2. Open Qt Creator, File > Open File or Project... > Locate `CMakeLists.txt` and open it
3. Click **Run**
> ### Without Qt Creator
You can also build without Qt Creator, if your system has `CMake` & `Make`. 
1. Download the repo
2. Run `cmake CMakeLists.txt` then `make` in the **SoCraps** folder
3. Ensure permissions allow `SoCraps` to execute & Run `SoCraps`

---
