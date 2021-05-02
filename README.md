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
        "married" : False 
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
  JSON'u daha iyi anlamak için gerçek bir örnekte inclemek daha yararlı olacaktır. Nodejs'in kurulumu ile gelen NPM'i "init" ederek oluşturduğumuz package.json dosyasını inceleyelim. Burada nodejs kullanılarak oluşturulmaya çalışılan basit bir blog sitesinin json dosyası bulunmaktadır. Bu dosya, proje ile dependencies ve versiyonları ilgili genel bilgir verir.
  
  ```json 
  {
    "name": "nodeblog",                                       // Proje adı.
    "version": "1.0.0",                                       // Proje versiyonu.
    "description": "Node Blog Application",                   // Proje'nin açıklama bölümü.
    "main": "index.js",                                       // Proje'nin başlangıç noktasını.
    "scripts": {
      "test": "echo \"Error: no test specified\" && exit 1"   // Komut dosyası komutlarını içeren bir sözlüktür.
       },
    "author": "Bogrek",                                       // Projeyi yazan kişi.
    "license": "ISC",                                         // Projenin lisansı.
    "dependencies": {                                         // Proje dosyalarının çalışması için gerekli olan framework'leri gösterir.  
      "express": "^4.17.1"                                    // Proje'nin express.js'e bağlı olduğunu ve versiyonunu belirtir.
    },                                                     // Versiyon gösterimindeki "^" işareti minör ve patch değişikliklerinin otomatik yapılacağını gösterir.
    "devDependencies": {                                      // Nodemon paketini de dependencies kısmında kullanabilirdik fakat projenin sadece development ...
      "nodemon": "^2.0.7"                                     // kısmında kullanılacağı için production kısmında gösterilmiyor.
   }
  }
  ```
  
  
