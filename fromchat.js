function processarString(inputString) {
    let resultado = '';
    let caractereAnterior = null;
  
    for (let i = 0; i < inputString.length; i++) {
      const caractereAtual = inputString[i];
  
      if (caractereAtual === 'M') {
        if (caractereAnterior !== null) {
          resultado += caractereAnterior;
        }
      } else {
        resultado += caractereAtual;
        caractereAnterior = caractereAtual;
      }
    }
  
    return resultado;
  }
  
  const inputString = "Exemplo de MManipulação de Mstrings";
  const resultado = processarString(inputString);
  
  console.log("String original:", inputString);
  console.log("String processada:", resultado);
  