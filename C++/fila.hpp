class Fila {
    private:
        Lista *lista;
    public:
        Fila() {
            lista = new Lista();
        }
        void mostrar(){
            lista->mostrar();
        }
        void enfileirar(int value){
            lista->inserirFinal(value);
        }
        void desenfileirar(){
            lista->deletarInicio();
        }
};
