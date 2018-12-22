function MyClass(label)
{
    this.label = label;
}

MyClass.prototype.updateText = function(str)
{
    this.label.text = str;
}

function updateText(str)
{
    label1.text = str;
}


wgt.windowTitle = "Signal And Slots";
lineedit.text = "Test";
lineedit.textChanged.connect(updateText);                       //соединяем сигнал textChanged из cpp QLineEdit с функцией js updateText
var myObject = new MyClass(label2);
lineedit.textChanged.connect(myObject, myObject.updateText);    //соединяем сигнал textChanged из cpp QLineEdit с методои js MyClass.updateText
lineedit.textChanged.connect(label3.setText);                   //соединение на прямую, сигнал из QLineEdit в слот QLabel.setText
lineedit.textChanged.connect(function(str) { label4.text = str; } );
