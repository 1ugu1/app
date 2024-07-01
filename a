# Listando processos para escolha do processo alvo
Get-Process | Format-Table -Property Id, ProcessName, MainWindowTitle

# Escolha o processo alvo com base no Id ou no Nome do processo
$targetProcessId = Read-Host "Digite o Id do processo alvo ou o nome do processo (ex: notepad.exe):"

if ($targetProcessId -match '\d+') {
    $targetProcess = Get-Process -Id $targetProcessId
} else {
    $targetProcess = Get-Process -Name $targetProcessId
}

if ($targetProcess -eq $null) {
    Write-Output "Processo alvo não encontrado."
} else {
    $token = $targetProcess.Handle
    $impersonatedToken = [IntPtr]::Zero

    # Chamando função API para impersonate token
    $success = [advapi32]::DuplicateToken($token, 2, [ref]$impersonatedToken)

    if ($success -eq 0) {
        Write-Output "Falha ao impersonar token."
    } else {
        Write-Output "Token impersonado com sucesso."
    }
}
