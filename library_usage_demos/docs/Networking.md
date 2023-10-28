

- Blocking Socket I/O
- HTTP protocol
- Rest
	


------------------------------------------------------------------------------------------------------------------------------------------------------
Blocking Socket I/O
------------------------------------------------------------------------------------------------------------------------------------------------------
					

By default, TCP sockets are placed in a blocking mode. 
This means that the control is not returned to your program until some specific operation is complete.

For example, if you call the connect() method, the connection blocks your program until the operation is complete. 
On many occasions, we don't want to keep our program waiting forever.

Taking another example, when we write a web browser client that connects to a web server, we should consider a stop functionality that can cancel an active connection process in 
the middle of its operation. This can be achieved by placing the socket in the non-blocking mode.

A socket is in blocking mode when an I/O call waits for an event to complete. If the blocking mode is set for a socket, the calling program is suspended until the expected event completes.

Using a blocking socket, execution will wait (ie. "block") until the full socket operation has taken place. So, you can process any results/responses in your code immediately after. 
These are also called synchronous sockets.

A non-blocking socket operation will allow execution to resume immediately and you can handle the server's response with a callback or event. 
These are called asynchronous sockets.

Blocking server uses a dedicated process/thread to handle a single income request.

In non-blocking server a process/thread is able to handle multiple requests at the same time. 
It could be possible because usually most of the time a request is in a state of waiting of a result of I/O operation (reading file, waiting result of a db query, 
waiting result of http request to some web-service etc.). So while one request is in the "wait" state the process/thread can handle other request which is in "ready" state.

From point of view programming a handler of a blocking server is simple. 
It just process input request by a dedicated process/thread. 
On the other hand a handler in a non-blocking server should somehow notify the process/thread in which state it is either in waiting for I/O result or it received an 
I/O result and ready to continue process.


--
Sources:
https://www.studytonight.com/network-programming-in-python/blocking-and-nonblocking-socket-io



------------------------------------------------------------------------------------------------------------------------------------------------------
HTTP protocol
------------------------------------------------------------------------------------------------------------------------------------------------------


REQUEST
--------------------------

The only header field that is actually required is Host. The Host field tells the web server
which web host the client is requesting the resource from. This is important because one
web server may be hosting many different websites. The request line tells the web server
that the /page1.htm document is wanted, but it doesn't specify which server that page is
on. The Host field fills this role.

__________________________________________________________________________
GET /page1.htm HTTP/1.1										
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36
Accept-Language: en-US
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Encoding: gzip, deflate
Host: example.com
Connection: Keep-Alive
__________________________________________________________________________


The only header field that is actually required is Host. The Host field tells the web server
which web host the client is requesting the resource from. This is important because one
web server may be hosting many different websites. The request line tells the web server
that the /page1.htm document is wanted, but it doesn't specify which server that page is
on. The Host field fills this role.

Each line of an HTTP message ends with a carriage return, followed by a newline character. 
In C, this looks like \r\n.

The web client must send a blank line after the HTTP request header. This blank line is how
the web server knows that the HTTP request is finished. Without this blank line, the web
server wouldn't know whether any additional header fields were still going to being sent.
In C, the blank line looks like this: \r\n\r\n


RESPONSE
-----------------------

__________________________________________________________________________
HTTP/1.1 200 OK
Cache-Control: max-age=604800
Content-Type: text/html; charset=UTF-8
Date: Fri, 14 Dec 2018 16:46:09 GMT
Building a Simple Web Client Chapter 6

Etag: "1541025663+gzip"
Expires: Fri, 21 Dec 2018 16:46:09 GMT
Last-Modified: Fri, 09 Aug 2013 23:54:35 GMT
Server: ECS (ord/5730)
Vary: Accept-Encoding
X-Cache: HIT
Content-Length: 1270

<!doctype html>
<html>
<head>

 
<title>Example Domain</title>
__________________________________________________________________________

HTTP/1.1 200 OK
Content-Type: text/plain; charset=ascii
Transfer-Encoding: chunked

44
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eius
37
mod tempor incididunt ut labore et dolore magna aliqua.
0
__________________________________________________________________________
In the preceding example, we see the HTTP body starts with 44 followed by a newline. This
44 should be interpreted as hexadecimal. We can use the built-in C strtol() function to
interpret hexadecimal numb


RESPONSE CODES
-----------------

200 OK: The client's request is successful, and the server sends the requested
resource
If the resource has moved, the server can respond with a code in the 300 range. These codes
are commonly used to redirect traffic from an unencrypted connection to an encrypted one,
or to redirect traffic from a www subdomain to a bare one. They are also used if a website has
undergone restructuring, but wants to keep incoming links working. The common 300
range codes are as follows:

301 Moved Permanently: The requested resource has moved to a new location.
This location is indicated by the server in the Location header field. All future
requests for this resource should use this new location.
307 Moved Temporarily: The requested resource has moved to a new location.
This location is indicated by the server in the Location header field. This move
may not be permanent, so future requests should still use the original location.

Errors are indicated by 400 or 500 range response codes. Some common ones are as follows:

400 Bad Request: The server doesn't understand/support the client's request
401 Unauthorized: The client isn't authorized for the requested resource
403 Forbidden: The client is forbidden to access the requested resource
500 Internal Server Error: The server encountered an error while trying to
fulfill the client's request

 
 
HTTP POST request:
---------------------------- 
__________________________________________________________________________
POST /orders HTTP/1.1
Host: example.com
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:64.0)
Content-Type: application/json
Content-Length: 56
Connection: close

{"symbol":"VOO","qty":"10","side":"buy","type":"market"}

__________________________________________________________________________

In the preceding example, you can see that the HTTP POST request is similar to an HTTP
GET request. Notable differences are as follows: the request starts with POST instead of GET;
a Content-Type header field is included; a Content-Length header field is present; and
an HTTP message body is included. In that example, the HTTP message body is in JSON
format, as specified by the Content-Type header

__________________________________________________________________________
POST /submission.php HTTP/1.1
Host: 127.0.0.1:8080
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7)
Accept-Language: en-US
Accept-Encoding: gzip, deflate
Content-Type: application/x-www-form-urlencoded
Content-Length: 31
Connection: keep-alive

name=Alice&comment=Well+Done%21

__________________________________________________________________________
In the preceding HTTP request, you can see that Content-Type: application/x-wwwform-urlencoded is used. 
In this format, each form field and value is paired by an equal
sign, and multiple form fields are chained together by ampersands.
Special characters in form field names or values must be encoded. Notice that Well Done!
was encoded as Well+Done%21. Spaces are encoded with plus symbols, and special
characters are encoded by a percent sign followed by their two-digit hexadecimal value
(thus, the exclamation point was encoded as %21). A percent sign itself would be encoded


__________________________________________________________________________
POST /submit.php HTTP/1.1
Host: example.com
Content-Type: multipart/form-data; boundary=-----------233121195710604
Content-Length: 1727

-------------
233121195710604
Content-Disposition: form-data; name="name"

Alice
-------------233121195710604
Content-Disposition: form-data; name="comment"

Well Done!
-------------233121195710604
Content-Disposition: form-data; name="file"; filename="upload.txt"
Content-Type: text/plain

Hello.... <truncated>
__________________________________________________________________________

As you can see, when using multipart/form-data, each section of data is separated by a
boundary. This boundary is what allows the receiver to delineate between separate fields or
uploaded files. It is important that this boundary is chosen so that it does not appear in any
submitted field or uploaded file!


--
Sources:
Book "Network programming in C"  by Lewis Van Winkle




------------------------------------------------------------------------------------------------------------------------------------------------------
The REST API
------------------------------------------------------------------------------------------------------------------------------------------------------

All resource identifiers are specified relative to the root:
http://host:port/wbe/rest/r1

where:
host 					is the DNS name or the IP address of the computer.
port 					is the port number through which the WebSphere® Application Server serves web pages.
wbe/rest 				indicates a request to the REST API.
r1 						is the version number of the URI. The version number is to prevent compatibility problems when changes are made to the REST API.


To access the resources the REST API provides four HTTP verbs, that perform the following operations:

POST to create a resource
GET to read a resource
PUT to update (or in some cases to create) a resource
DELETE to delete a resource


The REST API supports the following data formats:

application/json:
application/json indicates JavaScript Object Notation (JSON) and is used for most of the resources.

application/xml:
application/xml indicates eXtensible Markup Language (XML) and is used for selected resources.

application/x-wbe+xml:
application/x-wbe+xml indicates the Decision Server Events internal XML format, and is used for a small number of resources, 
specifically to support the import, export, and deployment of event projects to hosted event projects and the event runtime.

multipart/form-data:
multipart/form-data format is also understood in a small number of cases, where it is used to support uploading files from a browser.

application/x-www-form-urlencoded:
application/x-www-form-urlencoded might be required in a small number of circumstances to work around URI length limits when querying the REST API.


A API RESTful tem quatro métodos de autenticação comuns:

Autenticação de HTTP:

O HTTP define alguns esquemas de autenticação que você pode usar diretamente ao implementar a API REST. Estes são dois desses esquemas:

Autenticação básica

Na autenticação básica, o cliente envia o nome de usuário e a senha no cabeçalho da solicitação. 
Ele os codifica com base64, que é uma técnica de codificação que converte o par em um conjunto de 64 caracteres para transmissão segura.

Autenticação do portador

O termo autenticação do portador se refere ao processo de dar controle de acesso ao portador do token.
O token do portador é normalmente uma cadeia de caracteres criptografada que o servidor gera em resposta a uma solicitação de login.
O cliente envia o token nos cabeçalhos de solicitação para acessar recursos.

Chaves de API:
As chaves de API são outra opção para autenticação da API REST. Nessa abordagem, 
o servidor atribui um valor gerado exclusivo a um cliente iniciante. Sempre que o cliente tenta 
acessar recursos, ele usa a chave de API exclusiva para verificar a si mesmo. 
As chaves de API são menos seguras porque o cliente precisa transmitir a chave, o que a torna vulnerável a roubo de rede.

OAuth:
OAuth combina senhas e tokens para acesso de login altamente seguro a qualquer sistema. 
Primeiro, o servidor solicita uma senha e, depois, um token adicional para concluir o processo de autorização. 
Ele pode verificar o token a qualquer momento e também ao longo do tempo com escopo e longevidade específicos.


Exemplos:

GET http://mybookmarks.com/bookmarks

A resposta dessa requisição poderia ser algo do tipo:

<bookmarks>
<bookmark>
<id>1</id>
<title>Google</title>
<url>http://google.com</url>
</bookmark>
<bookmark>…</bookmark>
</bookmarks>
Lembrando que o formato, XML no exemplo, é livre e definido pelo provedor do serviço. Caso esse mesmo serviço fornecesse a saída em JSON, o resultado da requisição que fizemos seria algo como:

[
{“id” : 1, “title” : “Google”, “url” : “http://google.com” },
{“id” : 1, “title” : “Yahoo!”, “url” : “http://yahoo.com” }
]
Se ao invés da lista, quiséssemos recuperar apenas um bookmark específico, poderíamos utilizar o HTTP GET para uma URL que representasse esse único registro, por exemplo:

GET http://mybookmarks.com/bookmarks/13

ou

GET http://mybookmarks.com/bookmarks?id=13

Vale ressaltar que o modelo REST não impõe o formato da URL, deixando isso a cargo de quem provê o serviço. 
A única recomendação é que se use uma URL que identifique, de forma clara e única, o recurso que está sendo acessado.

Por sua vez, se quiséssemos incluir um novo bookmark, provavelmente iríamos utilizar a mesma URL da listagem, 
porém com o método HTTP POST e informaríamos os dados do objeto novo no corpo da requisição. Vejamos um exemplo:

POST http://mybookmarks.com/bookmarks

{“title” : “Google”, “url” : “http://google.com”}

Seguindo a mesma linha de raciocínio, se quiséssemos alterar um registro existente, 
poderíamos utilizar o método HTTP PUT juntamente com a URL do item específico que desejamos alterar. Por exemplo:

PUT http://mybookmarks.com/bookmarks/1

{“title” : “Google Brasil”, “url” : “http://www.google.com.br”}

E da mesma forma, se quiséssemos remover um registro, bastaria enviar uma requisição do 
tipo HTTP DELETE para a URL correspondente ao item a ser removido. A requisição ficaria parecida com a seguinte:

DELETE http://mybookmarks.com/bookmarks/1

Em todos os casos citados, devemos utilizar o código de status HTTP para saber se nossa solicitação foi efetuada com sucesso.
 No caso de ocorrer algum problema, o servidor deverá retornar um código de erro adequado, opcionalmente acompanhado de uma mensagem. Mais uma vez, fica a cargo do servidor definir seu funcionamento particular; nesse caso, quais códigos de erro retornar em cada situação.

Como podemos perceber, o modelo é simples e intuitivo, o que nos leva a perceber o quanto costumávamos subestimar o poder do protocolo HTTP. 
Felizmente, o REST veio para nos mostrar como é possível realizar praticamente qualquer operação utilizando puramente os recursos desse protocolo.


Sources:
https://www.ibm.com/docs/en/odm/8.8.1?topic=resources-rest-api
https://aws.amazon.com/pt/what-is/restful-api/
https://www.devmedia.com.br/rest-tutorial/28912

