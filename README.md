# Advanced-Keylogger-Cpp-Coding-Club-Project

## A Keylogger which keep tracks of the keystrokes and send's it to a telegram bot.

 - Demo

https://user-images.githubusercontent.com/87669561/179514685-86dd078f-4c91-4b77-9cb4-a09854214e98.mp4


## How To Use

### Create and set a telegram bot
#### Create your bot
* First in Telegram's search bar write `@BotFather`
* In chat with `BotFather` text him `/newbot`
* Name your bot
* `BotFather` will send you your api token, save it somewhere, you'll need it later
* Text to BotFather `/setprivacy`
* Choose your bot
* Text him `Disable`

#### Create a channel
* Create a new channel
* Add your bot as admi

### Set const variables
* First send any message on your telegram channel
* Then go to `https://api.telegram.org/bot<api Token>/getUpdates` and find `"id"` 
* Your token is [there](#Create-and-set-a-telegram-bot) 
* After that set `keylogg.hpp - > BOTAPI` as your api token
* And `keylogg.hpp -> CHAT_ID` as your id that you find before
* Set `keylogg.hpp -> LOGFILENAME` as name of file where logs will be

### Compile
* To directory with repo put [cpr](https://github.com/whoshuu/cpr) lib
* Create project with `keylogg.hpp` and `main.cpp`
* Go to Project -> <Project Name> propeties -> Advanced -> Character Set -> Use Multi-Byte
* Compile
* If you have problem with compiling or anything else DM me on Discord (my tag is in github profile description)
* Put it anywhere you want (If you have turned on [autostart](#autostart) it will copy itself to %temp% else you have to hide it manually and add it to autostart)
* Run it
* enjoy unethical but beautiful spying!

## Please use it wisely.
