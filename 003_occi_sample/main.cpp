#include <gtkmm.h>
#include <occi.h>
#include <iostream>

using namespace oracle::occi;
using namespace std;

class FormularioBD : public Gtk::Window {
private:
    Gtk::Box m_caja_vertical;
    Gtk::Entry m_entrada_datos;
    Gtk::Button m_boton_insertar;

public:
    FormularioBD() : m_caja_vertical(Gtk::Orientation::VERTICAL, 10) {
        set_title("Formulario de Inserción OCI");
        set_default_size(300, 100);
        
        // En GTK4 el margen se aplica directamente al widget, no hay set_border_width en la ventana
        m_caja_vertical.set_margin(10);

        m_boton_insertar.set_label("Insertar en Base de Datos");
        
        // GTK4 utiliza append() en lugar de pack_start()
        m_caja_vertical.append(m_entrada_datos);
        m_caja_vertical.append(m_boton_insertar);

        // GTK4 utiliza set_child() en lugar de add()
        set_child(m_caja_vertical);

        m_boton_insertar.signal_clicked().connect(sigc::mem_fun(*this, &FormularioBD::on_boton_insertar_clicked));
    }

    void on_boton_insertar_clicked() {
        Environment* env = nullptr;
        Connection* conn = nullptr;
        Statement* stmt = nullptr;

        Glib::ustring texto_a_insertar = m_entrada_datos.get_text();

        try {
            env = Environment::createEnvironment(Environment::DEFAULT);

            // Conexión directa al Wallet usando tu alias específico
            conn = env->createConnection("", "", "mqroci_bd_lab");

            cout << "¡Conexión exitosa a mqroci_bd_lab!" << endl;

            stmt = conn->createStatement("INSERT INTO bitacora (mensaje) VALUES (:1)");
            stmt->setString(1, texto_a_insertar.raw()); 
            
            stmt->executeUpdate();
            conn->commit();

            cout << "Dato insertado: " << texto_a_insertar << endl;
            m_entrada_datos.set_text(""); 

        } catch(SQLException& ex) {
            cerr << "Error de base de datos: " << ex.getMessage() << endl;
        }

        if (stmt) conn->terminateStatement(stmt);
        if (conn) env->terminateConnection(conn);
        if (env) Environment::terminateEnvironment(env);
    }
};

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.tu_dominio.app_bd");
    
    // GTK4 utiliza make_window_and_run
    return app->make_window_and_run<FormularioBD>(argc, argv);
}
