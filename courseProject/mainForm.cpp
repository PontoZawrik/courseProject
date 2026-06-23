#include "mainForm.h"
#include "LoginForm.h"
#include <Windows.h>
using namespace courseProject;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LoginForm^ login = gcnew LoginForm();

	if (login->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		Application::Run(gcnew mainForm());
	}

	return 0;
}