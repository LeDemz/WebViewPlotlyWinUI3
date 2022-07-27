#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <Python.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PlotlyExample::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        PyObject* pInt;

        Py_Initialize();

        char path[256] = "C:\\Users\\alexa\\OneDrive\\Polytechnique\\Documents2\\PlotlyExample\\PlotlyExample\\x64\\Debug\\PlotlyExample\\plotlyscript.py";
        
        PyObject* obj = Py_BuildValue("s", path);
        FILE* file = _Py_fopen_obj(obj, "r+");
        if (file != NULL) {
            PyRun_SimpleFile(file, path);
        }

        Py_Finalize();

    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        //myButton().Content(box_value(L"Clicked"));
    }
}
