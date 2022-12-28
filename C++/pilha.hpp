class Pilha {
    private:
        Lista *lista;
    public:
	    Pilha() {
	        lista = new Lista();
	    }
	    void mostrar(){
	        lista->mostrar();
	    }
	    void empilhar(int value){
	        lista->inserirInicio(value);
	    }
	    void desempilhar(){
	        lista->deletarInicio();
	    }
};
    
