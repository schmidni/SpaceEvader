mkdir build_win
cd build_win

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"
cmake -D WIN_Build=ON ..
devenv SDL2Test.sln /build
pause
