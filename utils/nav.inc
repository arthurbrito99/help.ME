<nav class="navbar default-primary-color hide-on-small-only">
    <div class="container center-align">
        <a class="brand-logo" href="../index.php"><i class="fa fa-handshake-o" aria-hidden="true"></i></a>
        <?php
        $logado = IsLogado("../usuario/users.json");
            if($logado){
                $usuario = $_SESSION['user'];
            ?>
                <ul class="right">
                    <li><a href="../usuario/pedido.php">Fazer Proposta</a></li>
                    <li><a href="../usuario/historico_doacao.php">Histórico de Contribuições</a></li>
                    <li><a><i class="fa fa-user" aria-hidden="true"></i> <?=$usuario->nome?></a></li>
                    <li><a href="../usuario/carteira.php"><i class="fa fa-money" aria-hidden="true"></i> R$:<?=$usuario->carteira?></a></li>
                    <li><a href="../usuario/deslogar.php"><i class="fa fa-sign-out" aria-hidden="true"></i> Sair</a></li>
                </ul>
            <?php
            }
            else if(Eh_Admin()){
            ?>
                <ul class="right">
                    <li><a href="../admin/historico_doacao_aprovada.php">Histórico de Contribuições</a></li>
                    <li><a href="../usuario/deslogar.php"><span class="glyphicon glyphicon-log-in"></span> Sair</a></li>
                </ul>

            <?php
            }   
            else{
                $link = $_SERVER["PHP_SELF"];
                $termo = "login.php";
                $pattern = '/'.$termo.'/';
                if(!preg_match($pattern,$link)){
                    $redirect = "../usuario/login.php";
                    header("location:$redirect");
                }
            }
            ?>
    </div>
</nav>




<nav class="hide-on-med-and-up default-primary-color">
    <div class="nav-wrapper">
        <a class="brand-logo center" href="../index.php"><i class="fa fa-handshake-o" aria-hidden="true"></i></a>
        
        <div>
            <ul id="slide-out" class="side-nav show-on-small">
                <li><a href="../usuario/pedido.php">Fazer Proposta</a></li>
                <li><a href="../usuario/historico_doacao.php">Histórico de Contribuições</a></li>
                <li><a><i class="fa fa-user" aria-hidden="true"></i> <?=$usuario->nome?></a></li>
                <li><a href="../usuario/carteira.php"><i class="fa fa-money" aria-hidden="true"></i> R$:<?=$usuario->carteira?></a></li>
                <li><a href="../usuario/deslogar.php"><i class="fa fa-sign-out" aria-hidden="true"></i> Sair</a></li>
            </ul>

            <a href="#" data-activates="slide-out" class="button-collapse"><i class="material-icons">menu</i></a>
        </div>
    </div>
</nav>
<script type="text/javascript">
    $(".button-collapse").sideNav();

</script>