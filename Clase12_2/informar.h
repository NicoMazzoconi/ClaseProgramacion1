int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

int clientesGastosContrataciones(Contratacion *arrayC, Pantalla *arrayP, int QTYC, int QTYP);
int cantidadContrataciones(Contratacion *arrayC, int QTYC, char *cuit);
int cuitGastos(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);

int ordenarPrecioNombre(Pantalla *arrayP, int QTYP);

int pantallasValorInferiorMil(Pantalla *arrayP, int QTYP);

float promedioPrecioPantalla(Pantalla *arrayP, int QTYP);
int listarPantallasPrecioMayorPromedio(Pantalla *arrayP, int QTYP);
int listarPantallasPrecioMenorPromedio(Pantalla *arrayP, int QTYP);

int pantallasMasUnaPublicacion(Pantalla *arrayP, int QTYP, Contratacion *arrayC, int QTYC);
int contarPublicacionesPantalla(Contratacion *arrayC, int QTYC, int idPantalla);

int diasContratadaPantalla(Contratacion *arrayC, int QTYC, int idPantalla);
int listarPantallaConFacturacion(Pantalla *arrayP, int QTYP, Contratacion *arrayC, int QTYC);
int pantallaMasFactracion(Pantalla *arrayP, int QTYP, Contratacion *arrayC, int QTYC);
