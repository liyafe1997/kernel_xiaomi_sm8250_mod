# About this repo

[中文](#中文)

## English
This repo (`android15-lineage22-mod` branch) is based on [Lineage OS 22.1 xiaomi sm8250 kernel source](https://github.com/LineageOS/android_kernel_xiaomi_sm8250).

Originally this repo (`android12-stable-mod` or `android14-stable-mod` branch) is fork from [UtsavBalar1231's repo](https://github.com/UtsavBalar1231/kernel_xiaomi_sm8250), but the `android14-stable` branch has freeze problem when the device sleep for a while or wake up. So now I switched to lineage22 codebase. The MIUI features code and some parts of the drivers is still copied from UtsavBalar1231's branch.

So still Thanks to [@UtsavBalar1231](https://github.com/UtsavBalar1231/)!

The main purpose of maintaining and building this kernel is to fix [this battery stuck at 1% problem](https://github.com/liyafe1997/Xiaomi-fix-battery-one-percent), and provide [SukiSU](https://github.com/ShirkNeko/SukiSU-Ultra)(A KernelSU fork with KPM support) & [SUSFS](https://github.com/sidex15/susfs4ksu-module) integrated pre-built image(flashable anykernel3 zip). Also provides a more intuitive and easy-to-use build script and build guide that allow you to try to build by yourself.

For using the SukiSU, you can install the SukiSU manager APK from [SukiSU Github Release](https://github.com/ShirkNeko/SukiSU-Ultra/releases). For the SUSFS module see [susfs4ksu-module Gihub Release](https://github.com/sidex15/susfs4ksu-module/releases).

(The devices affected by the "1% battery bug" are: alioth, apollo, lmi, thyme, umi, pipa. Because they all use the PM8150, aka Qualcomm fuel gauge GEN4. For the other devices are not affected by that bug, you can use this kernel for KernelSU purpose, as a replacement of the orginal stock kernel. Also, as the people tested, this kernel NoKernelSU version is good for applying [APatch](https://github.com/bmax121/APatch)).

The pre-built kernel image/zip is built on the `android15-lineage22-mod` branch. It should works on both stock MIUI and third-party AOSP based Android 11-15 ROMs. You are welcomed to give feedback (Issues/Pull Requests)!

Note: The zip does not include the `dtbo.img` and it will not replace your `dtbo` partition. It is recommanded to keep the stock `dtbo` or the `dtbo` from your third-party rom (If the builder comfirmed it works well). Since there are some problems with the `dtbo.img` which built from this source, one of them is the screen will suddently goes to the highest brightness when shut try to shut off the screen in the lock screen. If you had flashed any other third-party kernels, and you got some weird problem, you should keep an eye to check your `dtbo` has been replaced or not. 

**Notice: If you are using MIUI/HyperOS please use the MIUI varient. Because the display driver is different between MIUI and AOSP, if you are using MIUI/HyperOS but installed the AOSP version, the display will not work and only black screen. If you only see a black screen after installed this kernel, please check if you installed the correct varient or not!**

Supported devices:
| Code Name | Device Name                          |
|-----------|--------------------------------------|
| psyche    | Xiaomi Mi 12X                        |
| thyme     | Xiaomi Mi 10S                        |
| umi       | Xiaomi Mi 10                         |
| munch     | Poco F4 / Redmi K40S                 |
| lmi       | Redmi K30 Pro                        |
| cmi       | Xiaomi Mi 10 Pro                     |
| cas       | Xiaomi Mi 10 Ultra                   |
| apollo    | Xiaomi Mi 10T / Redmi K30S Ultra     |
| alioth    | Xiaomi Mi 11X / POCO F3 / Redmi K40  |
| elish     | Xiaomi Pad 5 Pro                     |
| enuma     | Xiaomi Pad 5 Pro 5G                  |
| dagu      | Xiaomi Pad 5 Pro 12.4                |
| pipa      | Xiaomi Pad 6                         |

Other Features/Improvement of this Kernel:
1. Support USB Serial (CH340/FTDI/PL2303/OTI6858/TI/SPCP8X5/QT2/UPD78F0730/CP210X).
2. Support EROFS.
3. F2FS realtime discard enabled for better TRIM the flash.
4. Support CANBus and USB CAN adapter (like CANable).
5. Support LZ4, LZ4HC, ZSTD compression algorithms for ZRAM.

## 中文
该repo (`android15-lineage22-mod` 分支)主要基于[Lineage OS 22.1 xiaomi sm8250 kernel source](https://github.com/LineageOS/android_kernel_xiaomi_sm8250)。

原来这个repo(即`android12-stable-mod`/`android14-stable-mod`分支)是fork自[UtsavBalar1231的仓库](https://github.com/UtsavBalar1231/kernel_xiaomi_sm8250)，但切到`android14-stable`分支的时候，发现那套代码有睡死问题（202408的几个release），所以现在切到了基于lineage22的代码来搞。MIUI特性的代码以及部分的设备驱动抠自UtsavBalar1231的仓库。

所以仍然感谢 [@UtsavBalar1231](https://github.com/UtsavBalar1231/)！

维护和编译这个内核的主要目的是想修复[电量卡在1%的问题](https://github.com/liyafe1997/Xiaomi-fix-battery-one-percent)，以及提供带[SukiSU](https://github.com/ShirkNeko/SukiSU-Ultra)(一个KernelSU的fork，支持KPM) & [SUSFS](https://github.com/sidex15/susfs4ksu-module)的预编译好的内核（请自行安装[SukiSU的管理器](https://github.com/ShirkNeko/SukiSU-Ultra/releases)以及根据需要刷上SUSFS模块）。以及再提供一个更直观和易用的编译脚本和README，方便大家自己折腾和修改，编译自己的内核！

（其中受“1%电量bug”影响的设备有：alioth, apollo, lmi, thyme, umi, pipa，因为它们都用了PM8150即高通的GEN4电量计。其它不受此bug影响的设备大可把这个内核当成个带SukiSU & SUSFS的官核平替，如果你想找一个带KernelSU的内核的话。并且据大家测试，该内核不带KernelSU版本可以应用[APatch](https://github.com/bmax121/APatch)）

Release里的编译好的内核成品由`android15-lineage22-mod`分支编译，应当能在原版MIUI和第三方的基于AOSP的各种Android11-15的ROM上使用。欢迎大家尝试并反馈（提Issue或Pull Requests）！酷友们到[酷安的这个帖子](https://www.coolapk.com/feed/56813047)讨论或反馈，也可以给我私信反馈！

注意：该内核的zip包不包含`dtbo.img`，并且不会刷你的dtbo分区。推荐使用原厂的`dtbo`，或者来自第三方系统包自带的dtbo（如果原作者确认那好用的话）。因为该源码build出来的`dtbo.img`有些小问题，比如在锁屏界面上尝试熄屏时，屏幕会突然闪一下到最高亮度。如果你刷过其它第三方内核，或者遇到一些奇怪的问题，建议检查一下你的`dtbo`是否被替换过。

**注意：如果你在用HyperOS/MIUI请刷MIUI的版本，AOSP版因为display驱动不同，在HyperOS/MIUI上屏幕无法正常显示，如果刷内核之后开机黑屏，请先检查你是不是正在用着HyperOS/MIUI但是刷了AOSP版**

度盘备用下载链接：https://pan.baidu.com/share/init?surl=11ocz7ggZ79gzRfWvsdbJA&pwd=ty58 （建议优先从Github Release下载）

欢迎加入内测QQ群: 459094061

支持的设备:
| 设备代号  | 设备名称                           |
|-----------|----------------------------------|
| psyche    | 小米12X                           |
| thyme     | 小米10S                           |
| umi       | 小米10                            |
| munch     | 红米K40S                          |
| lmi       | 红米K30 Pro                       |
| cmi       | 小米10 Pro                        |
| cas       | 小米10 Ultra                      |
| apollo    | 小米10T / 红米K30S Ultra          |
| alioth    | 小米11X / POCO F3 / 红米K40       |
| elish     | 小米平板5 Pro                     |
| enuma     | 小米平板5 Pro 5G                  |
| dagu      | 小米平板5 Pro 12.4                |
| pipa      | 小米平板6                         |

该内核的其他特性/改进:
1. 支持USB串口驱动（CH340/FTDI/PL2303/OTI6858/TI/SPCP8X5/QT2/UPD78F0730/CP210X）
2. 支持EROFS
3. F2FS开启了realtime discard以更好的TRIM闪存
4. 支持 CANBus 和 USB CAN （如 CANable）适配器（一些折腾嵌入式的可能会喜欢这个）
5. zRAM 支持 LZ4、LZ4HC、ZSTD 压缩算法

# How to build
1. Prepair the basic build environment. 

    You have to have the basic common toolchains, such as `git`, `make`, `curl`, `bison`, `flex`, `zip`, etc, and some other packages.
    In Debian/Ubuntu, you can
    ```
    sudo apt install build-essential git curl wget bison flex zip bc cpio libssl-dev ccache
    ```
    And also, you have to have `python` (only `python3` is not enough). you can install the apt package `python-is-python3`.

    In RHEL/RPM based OS, you can
    ```
    sudo yum groupinstall 'Development Tools'
    sudo yum install wget bc openssl-devel ccache
    ```

    Notice: `ccache` is enabled in `build.sh` for speed up the compiling. `CCACHE_DIR` has been set as `$HOME/.cache/ccache_mikernel` in `build.sh`. If you don't like you can remove or modify it.

2. Download [proton-clang] compiler toolchain

    You have to have `aarch64-linux-gnu`, `arm-linux-gnueabi`, `clang`. [Proton Clang](https://github.com/kdrag0n/proton-clang/) is a good prebuilt clang cross compiler toolchain.

    The default toolchain path is `$HOME/proton-clang/proton-clang-20210522/bin` which is set in `build.sh`. If you are using another location please change `TOOLCHAIN_PATH` in `build.sh`.

    ```
    mkdir proton-clang
    cd proton-clang
    wget https://github.com/kdrag0n/proton-clang/archive/refs/tags/20210522.zip
    unzip 20210522.zip
    cd ..
    ```

3. Build

    Build without KernelSU: 
    ```
    bash build.sh TARGET_DEVICE
    ```
    
    Build with KernelSU:
    ```
    bash build.sh TARGET_DEVICE ksu
    ```

    For example, build for lmi (Redmi K30 Pro/POCO F2 Pro) without KernelSU:
    ```
    bash build.sh lmi
    ````

    For example, build for umi (Mi 10) with KernelSU:
    ```
    bash build.sh umi ksu
    ```

    And also, here is a `buildall.sh` can build for all supported models at once.


