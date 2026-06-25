#include "mainForm.h"
#include "LoginForm.h"
#include <Windows.h>
using namespace courseProject;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	while (true) {
		LoginForm^ login = gcnew LoginForm();
		if (login->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
			break;
		}
		mainForm^ main = gcnew mainForm(login->currentUser);
		if (main->ShowDialog() != System::Windows::Forms::DialogResult::Retry) {
			break;
		}
	}

	return 0;
}