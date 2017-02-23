cmake_minimum_required(VERSION 3.6)
project(FaceRecognitionGUI)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Properties/AssemblyInfo.cs
        Properties/Resources.Designer.cs
        Properties/Resources.resx
        Properties/Settings.Designer.cs
        Properties/Settings.settings
        Resources/App.config
        App.config
        ConfigManager.cs
        EditTestSetDialog.cs
        EditTestSetDialog.Designer.cs
        EditTestSetDialog.resx
        FaceRecognitionGUI.csproj
        FaceRecognitionTask.cs
        MainForm.cs
        MainForm.Designer.cs
        MainForm.resx
        OptionsForm.cs
        OptionsForm.Designer.cs
        OptionsForm.resx
        PictureBoxNearestNeighbor.cs
        PictureForm.cs
        PictureForm.Designer.cs
        PictureForm.resx
        Program.cs
        README.txt
        Serialization.cs
        Settings.cs
        TestsetManagerForm.cs
        TestsetManagerForm.Designer.cs
        TestsetManagerForm.resx
        VisionDLL.cs)

add_executable(FaceRecognitionGUI ${SOURCE_FILES})