# A Planck layout with numpad and inverted-T home row arrows

On [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/57cf805069862b99fe1059e1b0988e0a)

![Keyboard](https://i.imgur.com/bUpW4bn.png)

[Install QMK](https://docs.qmk.fm/#/getting_started_build_tools?id=macos)

```
cd qmk_firmware
brew tap osx-cross/avr
brew tap PX4/homebrew-px4
brew update
brew install avr-gcc@8
brew link --force avr-gcc@8
brew install dfu-programmer
brew install dfu-util
brew install gcc-arm-none-eabi
brew install avrdude
```

To flash firmware (after installing QMK):

    cd qmk_firmware
    make planck:shawn:dfu

Then press the "reset" key combination

If that doesn't work, press the physical button on the back of the PCB, then run the `make` command
