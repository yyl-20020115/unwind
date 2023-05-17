
set ANDROID_NDK=c:\android-ndk-r13b

rmdir /s build_arm
mkdir build_arm 
cd build_arm

cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
	-DANDROID_ABI="armeabi-v7a" \
	-DANDROID_NDK=$ANDROID_NDK \
	-DANDROID_PLATFORM=android-19 \
	..

make

cd ..

