workspace "FR_EndYearExamination"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    targetdir "%{wks.location}/Bin/%{cfg.buildcfg}-%{cfg.architecture}"
    objdir "%{wks.location}/Int/%{cfg.buildcfg}-%{cfg.architecture}"

    startproject "Sandbox"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

    project "GameFramework"
        kind "SharedLib"
   	    language "C++"
	    cppdialect "C++17"
	    location "%{wks.location}/GameFramework"

        targetdir "%{wks.location}/Bin/Bin_FrameWork/%{cfg.buildcfg}-%{cfg.architecture}"
        objdir "%{wks.location}/Int/Int_FrameWork/%{cfg.buildcfg}-%{cfg.architecture}"

        files
        {
            "%{prj.location}/source/**.h",
            "%{prj.location}/source/**.cpp"
        }
        defines
        {
            "DLL_EXPORT"
        }
        includedirs
        {
            "%{prj.location}/source",
            "%{wks.location}/SFML/include/"
        }
        links
        {
            "%{wks.location}/SFML/Libs/sfml-audio.lib",
            "%{wks.location}/SFML/Libs/sfml-audio-d.lib",
            "%{wks.location}/SFML/Libs/sfml-graphics.lib",
            "%{wks.location}/SFML/Libs/sfml-graphics-d.lib",
            "%{wks.location}/SFML/Libs/sfml-main.lib",
            "%{wks.location}/SFML/Libs/sfml-main-d.lib",
            "%{wks.location}/SFML/Libs/sfml-system.lib",
            "%{wks.location}/SFML/Libs/sfml-system-d.lib",
            "%{wks.location}/SFML/Libs/sfml-window.lib",
            "%{wks.location}/SFML/Libs/sfml-window-d.lib"
        }
    
        postbuildcommands "{COPY} %{wks.location}/SFML/Libs/*.dll %{wks.location}/Bin/Bin_FrameWork/%{cfg.buildcfg}-%{cfg.architecture}"


    project "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        location "%{wks.location}/Sandbox"

        targetdir "%{wks.location}/Bin/Bin_Sandbox/%{cfg.buildcfg}-%{cfg.architecture}"
        objdir "%{wks.location}/Int/Int_Sandbox/%{cfg.buildcfg}-%{cfg.architecture}"

        files
        {
            "%{prj.location}/source/**.h",
            "%{prj.location}/source/**.cpp",
            "%{prj.location}/resources/**.png",
            "%{prj.location}/resources/**.jpg",
            "%{prj.location}/resources/**.wav"
        }

       includedirs
       {
         "%{wks.location}/FRAMEWORK/source",
         "%{wks.location}/SFML/include"
       }

        links
        {
            "%{wks.location}/FRAMEWORK/libs/GameFramework.lib",

            "%{wks.location}/SFML/Libs/sfml-audio.lib",
            "%{wks.location}/SFML/Libs/sfml-audio-d.lib",
            "%{wks.location}/SFML/Libs/sfml-graphics.lib",
            "%{wks.location}/SFML/Libs/sfml-graphics-d.lib",
            "%{wks.location}/SFML/Libs/sfml-main.lib",
            "%{wks.location}/SFML/Libs/sfml-main-d.lib",
            "%{wks.location}/SFML/Libs/sfml-system.lib",
            "%{wks.location}/SFML/Libs/sfml-system-d.lib",
            "%{wks.location}/SFML/Libs/sfml-window.lib",
            "%{wks.location}/SFML/Libs/sfml-window-d.lib"
        }

        postbuildcommands
        {
            "{COPY} %{wks.location}/FRAMEWORK/libs/*.dll %{wks.location}/Bin/Bin_Sandbox/%{cfg.buildcfg}-%{cfg.architecture}",
            "{COPYDIR} %{prj.location}/resources %{wks.location}/Bin/Bin_Sandbox/%{cfg.buildcfg}-%{cfg.architecture}/source/resources/",
            "{COPY} %{wks.location}/SFML/Libs/*.dll %{wks.location}/Bin/Bin_Sandbox/%{cfg.buildcfg}-%{cfg.architecture}" 
        }