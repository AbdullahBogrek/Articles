# JSON
- JSON "key ve value" çiftlerinden oluşan, verileri saklamak ve farklı platformlar arasında veri alışverişi yapmak için kullanılan ".json" uzantılı bir formattır.
  ```bash
  {"ad":"Abdullah", "soyad":"Bogrek"}
  ```
- Yapısı XML'e benzerdir. Fakat XML'e göre daha hızlı, daha az yer kaplar ve daha okunabilirdir. </br>
    XML
    ```XML
    <employees>
      <employee>
        <name>Abdullah</name>
        <surname>Bogrek</surname>
        <age>21</age>
      </employee>
      <employee>
        <name>Omer</name>
        <surname>Faruk</surname>
        <age>20</age>
      </employee>
    </employees>
    ```
    JSON
    ```JSON
    {
      "employees" : [
      {
        "name" : "Abdullah",
        "surname" : "Bogrek",
        "age" : 21,
        "married" : false 
      },
      {
        "name" : "Omer",
        "surname" : "Faruk",
        "age" : 20,
        "married" : false 
      }
                    ]
    }
    ```
- "Array, Object, Boolean, Number, String ve Null" veri tiplerini içerir. </br>
  Object
  ```JSON
  "employee" : {
    "ad" : "Abdullah"
  }
  ```
  Array
  ```JSON
  "employee":[
  {"name" : "Abdullah", "surname" : "Bogrek", "age" : 21},
  {"name" : "Omer", "surname" : "Faruk", "age" : 20}
  ]
  ```
  Number ve Boolean
  ```JSON
  {"age" : 21, "married" : false}
  ```
  Null
  ```JSON
  {"id" : null}
  ```
- JSON verilerini diğer programlama dillerinde (C#, Python, C++, Java, vb.) kullanabilmek için komutlarla programlama diline ait veri yapısına dönüştürülmelidir.
  Python'da json ile işlemler yapabilmek için 'json' kütüphanesini import ederiz. JSON verilerini kullanmak için 'load' fonksiyonunu, dict veri tipinde           yazılmış veriyi JSON formatına dönüştürmek için ise "dumps" fonksiyonu kullanılır. </br>
  Python
  ```python 
  import json
  
  employee = {
      'name' : 'Abdullah',
      'surname' : 'Bogrek',
      'age' : 21,
      'education' : {
            'university' : 'NEU',
            'branch' : 'Computer Engineering',
            'gpa' : 3.38,
      }
  }
  
  json_file = json.dumps(employee) 
  ```
  JSON kütüphanesi hakkında daha fazla bilgi için python'ın kendi [dökümanını](https://docs.python.org/3/library/json.html) inceleyebilirsiniz.</br>
  JavaScrit veriyi JSON formatına dönüştürmek için "stringify" methodunu, JSON nesnelerini JavaScript'e çevirmek için ise "parse" methodunu kullanır.</br>
  JavaScript
  ```javascript 
  
  var employee = {
      name : 'Abdullah',
      surname : 'Bogrek',
      age : 21,
      education : {
            university : 'NEU',
            branch : 'Computer Engineering',
            gpa : 3.38,
      }
  }
  
  json_file = JSON.stringify(employee) 
  ```
  
  ## Package.json
  JSON'u daha iyi anlamak için gerçek bir örnekte inclemek daha yararlı olacaktır. Nodejs'in kurulumu ile gelen NPM'i "init" ederek oluşturduğumuz package.json dosyasını inceleyelim. Burada nodejs kullanılarak oluşturulmaya çalışılan basit bir blog sitesinin json dosyası bulunmaktadır. Bu dosya, proje ile dependencies ve versiyonları ilgili genel bilgiler verir.
  
  ```json 
	{
	  "name": "nodeblog",
	  "version": "1.0.0",
	  "description": "Node Blog Application", 
	  "main": "index.js",
	  "scripts": {
	    "test": "echo \"Error: no test specified\" && exit 1"
	     },
	  "author": "Bogrek",
	  "license": "ISC",
	  "dependencies": {
	    "express": "^4.17.1"
	  },
	  "devDependencies": {
	    "nodemon": "^2.0.7"
	  }
	}
  ```
  - JSON dosyasındaki "name" proje adını, "versiyon" proje versiyonunu, "description" projenin açıklama bölümüdür. "main" projenin başlangıç noktasını, "author" projeyi yazan kişiyi, "license" projenin lisansını gösterir.
  - Buradaki "dependencies" proje dosyasının çalışması için gerekli olan framework'leri gösterir. Burada express.js'e bağlı olduğunu ve versiyonunu göstermektedir.
  - Versiyon gösterimindeki "^" işareti minör ve patch kısmınındaki güncellemeler otomatik olarak yapılacağını belirtmektedir.
  - Nodemon paketini de dependencies kısmında kullanabilirdik fakat projenin sadece development kısmında kullanılacağı için production kısmında değil de development kısmında gösteriliyor.
  - Örnekte de görüldüğü gibi json dosyası ile proje dosyalarımız hakkında birçok bilgiyi basit bir şekilde tutabiliriz.
  
  ## :books: Kaynaklar (Resources)
 - [JSON website](https://www.json.org/json-en.html)
 - [Python documents](https://docs.python.org/3/library/json.html)
 - [MDN Web Docs](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/JSON)
