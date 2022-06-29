workspace "FR_EndYearExamination"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    targetdir "%{wks.location}/Binaries/%{cfg.buildcfg}-%{cfg.architecture}"
    objdir "%{wks.location}/Intermediate/%{cfg.buildcfg}-%{cfg.architecture}"
    includedirs {"%{wks.location}/SFML/include"}
    libdirs {"%{wks.location}/SFML/Libs"}
    startproject "Sandbox"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

    project "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        location "%{wks.location}/Sandbox"

        --includes all files in source folder
        includedirs {"%{wks.location}/Sandbox/source"}


        files {
            "%{prj.location}/source/**.h",
            "%{prj.location}/source/**.cpp"
        }

        links {
        }

    project "GameFramework"
        kind "SharedLib"
   	    language "C++"
	    cppdialect "C++17"
	    location "%{wks.location}/GameFramework"

        targetdir "%{wks.location}/Binaries_FrameWork/%{cfg.buildcfg}-%{cfg.architecture}"
        objdir "%{wks.location}/Intermediate_FrameWork/%{cfg.buildcfg}-%{cfg.architecture}"

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
    
        postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/Binaries_FrameWork/%{cfg.buildcfg}-%{cfg.architecture}"