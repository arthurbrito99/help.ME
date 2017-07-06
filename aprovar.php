<?php
    ob_start(); // Initiate the output buffer
    require 'class_doacao.inc';
    session_start();

    $doacao = $_SESSION['doacao'];

    $descricao = $doacao->descricao;
    $meta = $doacao->meta;
    $autor = $doacao->autor;
    $aprovado = $doacao->aprovado;

    $controle = $_POST['controle'];
/*
        ESCRITA
*/

    $jsonString = file_get_contents('doacoes.json');
    $data = json_decode($jsonString, true);

    foreach ($data as $key => $entry) {
        if ($entry['id']==$controle) {
            $data[$key]['aprovado'] = 1;
   
            $dados = file_get_contents('aprovadas.json');
            $json = json_decode($dados);
            
            $json[] = array('finalidade'=>$data[$key]['finalidade'], 'meta'=>$data[$key]['meta'], 'autor'=>$data[$key]['autor'], 'aprovado'=>$data[$key]['aprovado'], 'arrecadado'=>$data[$key]['arrecadado'], 'id'=>$data[$key]['id'], 'descricao'=>$data[$key]['descricao']); 

            $dados_json = json_encode($json, JSON_PRETTY_PRINT);
            $arquivo = fopen("aprovadas.json", "w");
            fwrite($arquivo, $dados_json);
            fclose($arquivo);
        }
    }


    $dados_json = json_encode($data, JSON_PRETTY_PRINT);
    $arquivo = fopen("doacoes.json", "w");
    fwrite($arquivo, $dados_json);
    fclose($arquivo);


    $redirect = "index.php";
    header("location:$redirect");
?>