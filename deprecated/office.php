<?php
    $loggedon = file_exists("~/.loggedon");
    if(array_key_exists('html',$_REQUEST))
    {
        $html = true;
        if($loggedon)
        {
            echo "<html><head><title>Come join the party!</title></head>\n";
        }
        else
        {
            echo "<html><head><title>Nobody here...</title></head>\n";
        }
        echo "<body><pre>";
    }
    else
    {
        $html = false;
        header('Content-type: text/plain');
    }
    if($loggedon)
    {
        echo "                /-----\\\n";
        echo "                | \\o/ |\n";
        echo "There is probably someone in the office.\n";
    }
    else
    {
        echo "              /-----\\\n";
        echo "              |     |\n";
        echo "There is likely nobody in the office.\n";
    }
    if($html)
    {
        echo "</pre></body></html>";
    }
?>
