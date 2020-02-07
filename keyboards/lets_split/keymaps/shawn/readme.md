# A Let's Split layout with numpad and inverted-T home row arrows

On [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/a7d5417f7fd79a85605b1b5dbe43dcc2)

![Keyboard](https://i.imgur.com/vmZS9IG.png)

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

To flash firmware (after installing packages):

    cd qmk_firmware
    make lets_split:shawn:avrdude

Then press the reset key combination

Right is master, so plug that side in after flashing firmware (can be changed in config.h).
