# ABOAWT
As it name stands, "AOSP building on Android with Termux", I decided to take it
literally, and write a tool that can manage the process for the entire build of
AOSP, on an Android device.

For those unfamiliar, AOSP (Android Open Source Project) is the backbone of
Android's operating system. While it's open-source, manufacturers often add
proprietary layers and features, making only certain components like the kernel
open-source.

- "Android has a low-powered CPU!"
- "An Android device does not have enough RAM to even build it properly!"
- "Some devices don't have enough storage!"

Yeah, I get it. That's why I decided to address things, and write a proper tool
on building the AOSP. On Android. What, didn't you take a look at my GitHub
profile page, where I stated "to get things to another level"? Yeah, it is just
that. Taking things to another level.

## Requirements / Recommendations
Here are the requirements on what your device must meet, in order to actually
manage on making an AOSP build.

- ***Interactive Shell***: This application is written in C++, meaning that an 
  interactive shell is required. Applications like Termux help out with this.
- ***Root***: Your device must be rooted to operate under USB storage devices,
  along with operation on an SD card, if chosen during Execution Runtime. Unless
  the interactive Shell is being able to operate under a USB mass storage device
  without the Root Requirement, and has enough RAM to spare, this requirement can
  be bypassed.
- ***Kernel Configuration***: Your device's kernel must support the ability of
  managing Swap Space. Unless your device has more than 12 GB of RAM to spare,
  this can be considered more of a recommendation.
- ***Device Storage***: Your device's storage would require at least 512 GB for
  a full, non USB way. This will assume that you didn't pack quite a few apps on
  the device, and has enough storage for a proper build. Recommended device's
  storage is 1 TB.
- ***USB Host***: If your device does not meet the recommended storage space,
  where your device's internal storage only has 128 GB, your device requires
  **USB Host**. This will allow you to plug in a USB mass storage device that
  can exceed the internal device's storage limitation.
- ***USB Device***: In case of **USB Host** being a requirement, you will need to
  have a USB Mass Storage Device (or simply known as USB drive) with at least 512
  GB. 256 GB is required for either one of its tasks, which is either the download
  or building AOSP.
- ***CPU***: A 64-bit CPU is required, with the CPU being either aarch64 or
  x86_64 compatible. 32-bit CPUs are not supported due to use of some values
  exceeding 32-bit limits.

In short terms,

- An App like Termux is required.
- A rooted device is required, unless specific conditions allow to be bypassed.
- The kernel must be configured to support Swap space, unless 12 GB of RAM can
  be spared for use during build.
- For an internal-storage only way, a device with 1 TB is recommended.
- USB Host is required, if device storage does not meet the requirement.
- At least a 256 GB of Storage for a USB drive is required for a download or build;
  512 GB for both download and build.
- A 64-bit CPU is required (aarch64 / x86_64)

## Description
A longer description is coming soon. Be prepared, as it will juice up even more
features than you might expect...