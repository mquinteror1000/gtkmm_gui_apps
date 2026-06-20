#include <gtkmm.h>
#include <iostream>

// Heredamos de Gtk::Window para crear nuestra propia clase de ventana
class MiVentana : public Gtk::Window {
public:
    MiVentana() {
        // Configuramos las propiedades de la ventana
        set_title("Mi Primera App con GTK4");
        set_default_size(300, 200);

        // Configuramos el botón
        m_button.set_label("¡Haz clic aquí!");
        m_button.set_margin(50); // Un poco de espacio alrededor

        // Conectamos la señal 'clicked' del botón con nuestro método
        m_button.signal_clicked().connect(sigc::mem_fun(*this, &MiVentana::on_button_clicked));

        // Añadimos el botón a la ventana
        set_child(m_button);
    }

protected:
    // Nuestro manejador de la señal del botón
    void on_button_clicked() {
        std::cout << "¡Hola desde la terminal! El botón funciona." << std::endl;
        m_button.set_label("¡Clickeado!");
    }

    // Elementos de la interfaz
    Gtk::Button m_button;
};

int main(int argc, char* argv[]) {
    // Inicializamos la aplicación GTK con un identificador único
    auto app = Gtk::Application::create("org.martin.miapp");

    // Retornamos la ejecución de la aplicación, pasándole nuestra ventana
    return app->make_window_and_run<MiVentana>(argc, argv);
}
