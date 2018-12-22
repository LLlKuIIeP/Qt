function showFiles()
{
    var files = JSTools.dirEntryList(".", "*");
    JSTools.alert(files.join("\n"));
}

JSTools.print("JSTools test!");
cmdFiles.clicked.connect(showFiles);
cmdQuit.clicked.connect(function() { JSTools.quitApplication(); } );
