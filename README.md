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


## ������պе�ʹ�ã�
�Ѿ������˼��̺����Ľ��������̿����м������������ƶ����˹�����Camera�̶���Ҫ�ﵽ�������۵�Ч��ֻ�轫Camera���м����������а󶨡�
��dfz�ڴ˻�������ӵ��Σ���zzx�ڴ˻����ϵ���ģ�Ͳ���Camera�󶨣������ʹﵽ���ﳡ������Ч����
������պж���ϷЧ������Ƿ�ѣ����кõ���ͼ�����

*To do list(zzh): Lighting, Reflecting, Normal lighting...

## ������������
���е���ͼ��ģ���ļ������resources�ļ��У�������obj��texture�����ط�
�����ⲿinclude�����includes�ļ���
�����ⲿlib�����External Libraries�ļ���
������main.cppͬ�����ļ���ϵ����