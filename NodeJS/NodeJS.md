# NodeJS

- **Node.JS**, **Chrome V8 JavaScript Engine**'i temel alan bir **JavaScript** çalışma ortamıdır. Bu çalışma ortamı sayesinde **Javascript** kodlarını kullanmak için tarayıcı kısıtlamalarından kurtulmuş oluruz. En kısa ifadeyle **Node.JS** tarayıcılara ihtiyaç duymadan her yerde çalışabilir.

    - **V8**, Google'ın C++ ile yazılmış açık kaynaklı yüksek performanslı **JavaScript** ve WebAssembly motorudur. Diğerlerinin yanı sıra Chrome'da ve Node.js'de kullanılır. ECMAScript ve WebAssembly'yi uygular. Windows 7 ve sonrası, macOS 10.12+ ve x64, IA-32, ARM ya da MIPS işlemcileri kullanan Linux sistemlerde çalışır. Web sitesine [buradan](https://v8.dev/) ulaşabilirsiniz.
    
- **Node.JS**, **asenkron(asynchronous)** olarak çalışır. Kod akışı yukarıdan aşağıya değil, olaya(event) göre belirlenir. Bunun haricinde ise uzun süren işlemler tamamlandığında, bu uzun süren işlemlere bağımlı olan diğer işlemlere devam etmek ister. Buradaki sorumuz ise şu: Bu devam işlemler, uzun süren işlemin tamamlandığını nasıl bilecek? İşte burada callback devreye girer.

- **Node.JS**, **olay odaklı(event-driven)** çalışır. **JavaScript**'in single-thread olmasından dolayı, **Node.JS** kendisinden istenilen işleri bir olay döngüsü(event-loop) içerisinde değerlendirir. Böylece sırası gelen event yürütülür. 

- **Node.JS**, **non-blocking** olarak çalışır. İşlem sırasına koyduğu bir olayın tamamlanmasını beklemeden diğer olayı işleme alabilir, bunun sonucu olarak da iş akışı engellemez.

- **Node.JS** çalışma ortamının da bir terminali vardır ve buna **REPL(Read-Eval-Print-Loop)** denir. Kullanıcılara **Javascript** kodlarını çalıştırabileceğimiz bir komut satırı ortamı sunar.

- **Node.JS** asenkron yapısı ile uzun süren işlemlerin tamamlanmasını beklemeden diğer işlere devam etmek ve bunun haricinde ise uzun süren işlemler tamamlandığında, bu uzun süren işlemlere bağımlı olan diğer işlemlerin de devam etmeksini ister. Burada uzun süren işlemin tamamlandığını bilmek için **callback**'leri kullanır.

- **Node.JS** ile fonksiyon tanımlandığında, ilgili geri dönüş için **callback** fonksiyonu güzel bir çözüm. Ancak amaçlarımızdan birisi birbirleriyle ilişkili işlemlerin birbirine bağlı olarak çalışmasıydı. Fakat **callback** fonksiyonu ile sonuçları beklemek durumunda kalıyoruz. Bunun yerine, **Promise** yapısı kullanılarak işlem istenen sonucu alındığında devam edebilir, bir hata ile karşılaşıldığında da başka bir işlem yapılabilmekte.

    - Promise bir işlemin sonucunu temsil eden bir Javascript nesnesidir. Promise nesnesi Resolve ve Reject adında iki tane parametre alır ve olumlu durumlarda Resolve ile belirtilen işlemlerin, olumsuz durumlarda da Reject ile belirtilen işlemlerin yapılacağına dair güvence verir. Promise yapısı olumlu sonuçları .then(), olumsuz sonuçları da .catch() ile karşılar.

        ```js
            const promise1 = new Promise((resolve, reject) => {
                resolve("VERILER ALINDI");
                reject('BAĞLANTI HATASI');
            });

            promise1
                .then((value) => {
                    console.log(value);
                })
                .catch((error) => {
                    console.log(error);
                });
        ```

    - **Async - Await** yapısı ES8 ile birlikte gelmiş ve **Promise** yapısının daha anlaşılır bir söz dizimi ile yazılabilir halidir. Bir fonksiyon **async** anahtar kelimesi ile birlikte tanımlanırsa, fonksiyonun olumlu sonuçlanması sonucunda bir **Promise** döner. Bir **async** fonksiyon **await** anahtar kelimesi ile birlikte kullanılırsa ilgili **Promise** olumlu bir şekilde dönene kadar **async** fonksiyonunun çalışması bekletilir.

        ```js
            async function processData() {
                try {
                    const receivedData = await getData(true); 
                    console.log(receivedData);
                    const cleanedData = await cleanData(false);
                    console.log(cleanedData); 
                } catch (error) {
                    console.log(error);
                }
            }
        ```

- **Node.JS** içerdiği tüm JavaScript dosyalarına bir modül olarak davranır. Böylece kodun daha modülarize olmasını sağlanır. Bu da kod kontrolünü ve hata ayıklamanın daha kolay olmasını sağlar.

    ```js
        function fetchPost = () =>{
            ...
        }

        module.export = fetchPost
    ```
    - Node.js uygulamalarında birden daha fazla fonksiyon kullanıma açılır. Burada iki yöntem kullanılabilir. Fonksiyonlar direkt export edebilir ya da module.exports nesnesi içerisinde tanımlanabilir.

        ```js
            module.exports.fetchPost ...
            module.exports.fetchUser ...
            // or
            module.exports = {
                fetchPost,
                fetchUser
            }
        ```

- **Node.JS**, içerisinde çeşitli işlemleri yapabilmek için oluşturulmuş çekirdek modülleri varıdr. Bunlar **Node.JS** ile birlikte gelir. Tekrar oluşturulmaya gerek yoktur ve kullanıma hazırdır. Bunlar; console, http, fs, url, path ve dahası. Tam listesini ve kullanımını [buradan](https://flaviocopes.com/node-core-modules/) inceleyebilirsiniz.

- **Node.JS** ile yazılan bir web uygulaması request-response döngüsüdür. Request Headers içerisinde yaptığımız istek, Response Headers içerisinde ise aldığımız cevap ile ilgili bilgiler taşınır. İstekte bulunacağımız bilgisayarı **IP** adresi sayesinde buluruz. İki bilgisayar arasındaki veri alış-verişi ise **TCP/IP** kümesi ile gerçekleşir. Client ile server arasındaki iletişin kurallarını **HTTP** belirler.

- **Node.JS**'de client-server arasındaki iletişim, kendi core modülü olan **http** ile gerçekleştirilebileceği gibi, express ya da koa gibi framwork'ler ile de gerçekleştirilebilir. Çoğunlukla projelerde **[Express.js](https://www.npmjs.com/package/express)** kullanılmaktadır. Daha kolay ve daha hızlı bir kullanıma sahiptir.

    - **HTML**, **CSS** ve **JavaScript** dosyaları, görsellerin bulunduğu dosyalar static dosyalardır. Express uygulamalarında bu static dosyaları kullanabilmek için **Express** framework'ünde gömülü olarak bulunan `express.static` **middleware** fonksiyonu kullanılır.

        >**Middleware**, request-response cycle'ı içerisinde bulunan her şeydir. Request ve response arasında bir fonksiyon çalıştırabilir, request veya response nesnelerini manipüle edebilir,` next()` metodu ile sonraki middleware fonksiyonunu çağırabilir, request-response döngüsünü sonlandırabiliriz. `get` metodu da bir middleware'dır.

        - Sayfa içeriklerinin static yani değişmez içerikler olması yerine dinamik bir şekilde çalışmasını yani içeriğinde değişiklikler yapılabilmesi istenir. İşte burada da **template engine** kavramı devreye girer. Template engine'ler sayesinde bir static dosyaları ve değişen dinamik içerik birlikte kullanabilir. Farklı template engine'ler kullanılabilir. **Ejs**, **Pug** bunlara örnektir.
 
- Node.JS projesi geliştirilirken devamlı olarak server'ı yeniden başlatmak yerine bunu otomatik olarak yapan **[nodemon](https://www.npmjs.com/package/nodemon)** paketi de projelerde kullanılmaktadır. 

- Devam edecek...