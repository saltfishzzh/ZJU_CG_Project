# Project for ZJU CG 2017 spring&summer

## The configuration of Assimp in VS(load models)
1. C++/General/Additional Include dir
2. linker/Input/Additional Dependencies add:assimp.lib
3. linker/General/Additional library dir
4. copy "\Assimp\bin\x86\assimp-vc140-mt.dll" into the dir of debug

## The configuration of SOIL2 in VS(load images)
1. Download premake(recommend premake4) 
http://premake.github.io/download.html#v4
2. Download SOIL2 
https://bitbucket.org/SpartanJ/soil2/
3. Copy premake4.exe into the SOIL2's folder, which has the file premake4.lua
4. Go to cmd and cd to the SOIL2 folder, type "premake4.exe gmake"
5. Find soil2-debug.lib in ..\lib\windows, copy it to your VS project folder
6. Copy SOIL2 folder in ..\src to your VS project's folder to relative link or absolute link if you like
7. Add "$(SolutionDir) *your path of soil2-debug.lib*" to the "Additional Library Directories" in General Linker in the Property Pages
8. Add "soil2-debug.lib" to the input linker


## 关于天空盒的使用：
已经加入了键盘和鼠标的交互，键盘控制中间的立方体进行移动，此工程中Camera固定，要达到我们讨论的效果只需将Camera与中间的立方体进行绑定。
请dfz在此基础上添加地形，请zzx在此基础上导入模型并与Camera绑定，这样就达到人物场景漫游效果。
另：此天空盒对游戏效果可能欠佳，如有好的贴图请提出

*To do list(zzh): Lighting, Reflecting, Normal lighting...

## 关于整个工程
所有的贴图、模型文件请放入resources文件夹，其中有obj、texture两个地方
所有外部include请放入includes文件夹
所有外部lib请放入External Libraries文件夹
其他与main.cpp同级的文件关系不大