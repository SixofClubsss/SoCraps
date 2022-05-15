---
# SoCraps🎲
A simple craps style game written in C++/Qt.

Work in progress to help me learn. Used Qt 5.12.8 to build the Ui. The game is modeled off casino craps. Currently there is functional pass and don't pass line bets with point, place bets and onetime bets, repeat last bet buttons. A 7 rolled clears the table. 

🎲Deposit your play funds and roll the dice🎲

---
## Screenshot

![Screenshot 2022-05-15 15:51:44](https://user-images.githubusercontent.com/84689659/168495424-7a17ebf2-8193-44a2-b70f-7a5957b99f44.png)

---
### To Do List
- [ ] Add pass & don't pass odds bets, *3-4-5 game*
- [ ] Add multi outcome bets ie: *any crap, horn, hi lo, field*
- [X] Clean stuff up, might have some redundancies
- [X] Add pop up at the start with *how to play and rules* 
- [X] Fix maximize to make full screen 
- [X] Button colors don't work when built
- [ ] Further intergrations

---
## Build instructions
> ### With Qt Creator
1. Download and install Qt Creator (https://www.qt.io/download-open-source/)
2. Open Qt Creator, File > Open File or Project... > Locate `CMakeLists.txt` and open it
3. Click **Run**
> ### Without Qt Creator
You can also build without Qt Creator,

### Linux instructions

1. Install dependencies
```
sudo apt update
sudo apt install build-essential cmake 
sudo apt install --no-install-recommends qtbase5-dev qttools5-dev libqt5svg5-dev
```

2. Download repo & build
```
git clone https://github.com/SixofClubsss/SoCraps.git
cd SoCraps
cmake CMakeLists.txt
make
```

3. Start app
```
./SoCraps
```
#

---
