$kerbTicket = "YIIICQYGKwYBBQUCoIIBCzCCAXMCAQEwge6BpC+AnNmAAAAAAAMIGQBgkqhkiG9xIBAgICAG+BiDCBmrSggakwgaoxCzAJBgUrDgMCGgUAMAsGCSqGSIb3DQEHATGCAUEwggE9AgEBMBowGDAWBgorBgEEAYI3AgIKcQTCBuT1oIG+XjBcBgkqhkiG9xIBAgRTTVKgUgAAAAAAAxAAAAAAAAACAAAAADgAAACAAAABwLq8QQ4C+CGAzDfLpjN3AswANAAAABAAEAAAAAAAABAAAAMAAAAAABAAEAAAAAAAABAAEAAAAAAAABAAEAAAAAAAABAAEAAAAAAAABAAEAAAAAAAABAAEAAAAAAAAAAwAAAAAAAAAwAAAAAAAAAwAAAAAAAAAwAAAAIAAAACAAAAAgIAAAEAAAACAAAACQAAAAAAAAA0OQCAxH2U9r9OtBE7u+pp9mFXDNxRz3H3Ic7PBoBH+J+ysm8QX6p/JwF6CSsYEXgQfErhBGh7wMu6TkeJvvS3bCOfm1CD5KnyU3xqOZCl9NOvAZ/7Dp/SeK0PbC/XQko3lPTeJ1v3GvCbfZMyG8sLuF0tLX+1FiXel6J6QoG5C/mOz5ZyV6+Q3JdtF5Bqk5hGAgBFQAAgAAAAIAAAACAAAAEAAAABAAAAAAAAA4AAAAAAAAAIAAAACAAAAFAAAAAAAAAAwNDgwDQYJKoZIhvcNAQEFBQADggEBAK/c3EjOjKge8k2mXDCUI3CtmV3ChBIKzVtQxtkMwQlP25vzTT/d1+gnmpaBTkqH8xGVbX2I5Z16BfNv2qQX5Jct8Dp5Z8fLZtQ8LbQhE2Cdzv/hq60ecFrkOuJ4rS+UoCkUKLOdo7pHswso7+2Zw+dUxN8g96t9oTPO4gTDeyX/gO2L8wP52NGALMy/F78+jstVx1V7Ua7xHtM1x7qO0Sbo1kSlEYw0cs2Yz8AM4ipGIBNLzI7g4MCVf6Vg/5rEw9UFrY0p0brY5GcQvVQllJGhwZ0BxZ8A9ULAvSIfAl1pZlN6Uh+C9KRe/08UXobrg3GEGrIff0lFXtoZJp0SXEB"
Invoke-Command -ComputerName PDCPRI03 -ScriptBlock { $ticketBytes = [System.Text.Encoding]::Unicode.GetBytes($using:kerbTicket); klist add /c:protege.com.br /t:$ticketBytes }