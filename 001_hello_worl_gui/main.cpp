#include <gtkmm.h>
#include <iostream>

class MiVentana : public Gtk::Window {
public:
    MiVentana() {
        // Propiedades de la ventana 
        set_title("Mi Primera aplicacion con GTK4");
        set_default_size(600, 400);

        m_button.set_label("¡Haz clic aquí!");
        m_button.set_margin(50); 

        m_button.signal_clicked().connect(sigc::mem_fun(*this, &MiVentana::on_button_clicked));

        // Agregar el boton a la ventan 
        set_child(m_button);
    }

protected:
    // Manejador de la señal de boton
    void on_button_clicked() {
        std::cout << "hola, estamos trabajando con gtkmm 4.0" << std::endl;
        m_button.set_label("Boton presionado");
    }

    Gtk::Button m_button;
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.my_user.hellowork");

    // Retornamos la ejecución de la aplicación, pasándole nuestra ventana
    return app->make_window_and_run<MiVentana>(argc, argv);
}
