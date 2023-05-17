NDK=/c/android-ndk-r13b
NDKABI=19
NDKVER=$NDK/toolchains/arm-linux-androideabi-4.9
NDKP=$NDKVER/prebuilt/windows-x86_64/bin/arm-linux-androideabi-
NDKF="--sysroot $NDK/platforms/android-$NDKABI/arch-arm"  
NDKARCH="-march=armv7-a -mfloat-abi=softfp -Wl,--fix-cortex-a8 -fno-omit-frame-pointer"

make HOST_CC="gcc -m32" CROSS=$NDKP TARGET_SYS=Linux TARGET_FLAGS="$NDKF $NDKARCH"


