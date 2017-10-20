#pragma once
#include "frmUsuarioHome.h"
#include "frmAdministradorHome.h"

namespace SismografosView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Para trabajar con MySQL
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de frmLogin
	/// </summary>
	public ref class frmLogin : public System::Windows::Forms::Form
	{
	public:
		frmLogin(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnLetMeIn;
	private: System::Windows::Forms::TextBox^  txtUsuario;
	private: System::Windows::Forms::TextBox^  txtPassword;

	private: System::Windows::Forms::Label^  lblUsername;
	private: System::Windows::Forms::Label^  lblPassword;


	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmLogin::typeid));
			this->btnLetMeIn = (gcnew System::Windows::Forms::Button());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnLetMeIn
			// 
			this->btnLetMeIn->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->btnLetMeIn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnLetMeIn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnLetMeIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLetMeIn->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->btnLetMeIn->Location = System::Drawing::Point(156, 300);
			this->btnLetMeIn->Name = L"btnLetMeIn";
			this->btnLetMeIn->Size = System::Drawing::Size(192, 64);
			this->btnLetMeIn->TabIndex = 0;
			this->btnLetMeIn->Text = L"Let me in";
			this->btnLetMeIn->UseCompatibleTextRendering = true;
			this->btnLetMeIn->UseVisualStyleBackColor = true;
			this->btnLetMeIn->Click += gcnew System::EventHandler(this, &frmLogin::btnLetMein_Click);
			// 
			// txtUsuario
			// 
			this->txtUsuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtUsuario->BackColor = System::Drawing::Color::MediumPurple;
			this->txtUsuario->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsuario->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->txtUsuario->Location = System::Drawing::Point(120, 127);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->txtUsuario->Size = System::Drawing::Size(258, 30);
			this->txtUsuario->TabIndex = 1;
			this->txtUsuario->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtUsuario->TextChanged += gcnew System::EventHandler(this, &frmLogin::txtUsuario_TextChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtPassword->BackColor = System::Drawing::Color::MediumPurple;
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->txtPassword->Location = System::Drawing::Point(120, 187);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->txtPassword->Size = System::Drawing::Size(258, 30);
			this->txtPassword->TabIndex = 2;
			this->txtPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtPassword->UseSystemPasswordChar = true;
			this->txtPassword->TextChanged += gcnew System::EventHandler(this, &frmLogin::txtPasword_TextChanged);
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->BackColor = System::Drawing::Color::MediumPurple;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsername->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->lblUsername->Location = System::Drawing::Point(124, 130);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(99, 25);
			this->lblUsername->TabIndex = 3;
			this->lblUsername->Text = L"username";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->BackColor = System::Drawing::Color::MediumPurple;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPassword->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->lblPassword->Location = System::Drawing::Point(124, 189);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(96, 25);
			this->lblPassword->TabIndex = 4;
			this->lblPassword->Text = L"password";
			// 
			// frmLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(511, 405);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->btnLetMeIn);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"frmLogin";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmLogin";
			this->TransparencyKey = System::Drawing::Color::Black;
			this->Load += gcnew System::EventHandler(this, &frmLogin::frmLogin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btnLetMein_Click(System::Object^  sender, System::EventArgs^  e) {
			//Para trabajar con la base de datos
			String^ constring = L"datasource=35.193.73.44;port=3306;username=sebas;password=123456";
			MySqlConnection^conDataBase = gcnew MySqlConnection(constring);
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from credenciales.usuarios where usuario='"+this->txtUsuario->Text+"' and contrasena='"+this->txtPassword->Text+"' ;", conDataBase);
			MySqlDataReader^myReader;
			try {
				conDataBase->Open();
				myReader = cmdDataBase->ExecuteReader();
				int count = 0;
				//Cogemos la primera columna de la base de datos (id)
				while (myReader->Read()) {
					count = count + 1;
				}
				if (count == 1) {
					MessageBox::Show("Username and password is correct");
				}
				else if(count > 1){
					MessageBox::Show("Duplicate username and password ... Access deneid");
				}
				else {
					MessageBox::Show("Username and password is not correct");
				}
			}catch(Exception^ex){
				MessageBox::Show(ex->Message);
			}
			///////
			
			frmUsuarioHome^ ventanaUsuarioHome = gcnew frmUsuarioHome();
			frmAdministradorHome^ ventanaAdministradorHome = gcnew frmAdministradorHome();
			//Se captura lo que se escribe en las cajas de texto
			String^ usuario = txtUsuario->Text;
			String^ password = txtPassword->Text;
			if (usuario = "Administrador") {
				frmLogin::Hide();
				ventanaAdministradorHome->Show();
			}
			else if(usuario != ""){
				// ventanaSismografo->MdiParent = this;
				frmLogin::Hide();
				ventanaUsuarioHome->Show();
			}
		}
private: System::Void txtUsuario_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	lblUsername->Hide();
}
private: System::Void txtPasword_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	lblPassword->Hide();
}
private: System::Void frmLogin_Load(System::Object^  sender, System::EventArgs^  e) {
}

};
}
