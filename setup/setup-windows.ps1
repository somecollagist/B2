$env:ChocolateyInstall='C:\ProgramData\choco'		# This is so you can access choco programs without needing admin rights
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
[Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\ProgramData\choco\bin", "Machine")
[Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\ProgramData\choco\lib\mingw\tools\install\mingw64\bin", "Machine")
choco install mingw -yf --install-arguments="'/DIR=C:\ProgramData\choco'"
choco install make -yf --install-arguments="'/DIR=C:\ProgramData\choco'"