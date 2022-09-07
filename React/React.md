## NPM (**N**ode **P**ackage **M**anager)

- **NodeJS** ile birlikte hazır olarak gelen ve projelerdeki paket kurma ya da silme gibi paket yönetim işlemlerini yapmaya olanak sağlayan bir araçtır.

- Tamamen `javascript` kullanılarak geliştirilmiştir.

- Bir **NodeJS** projesinde yüklenen paketler, `node_modules` isimli klasörün altında tutulur. Kullanılan paketlerin versiyonları ve bağımlılıkları(`devDependencies` ya da `dependencies` gibi) proje klasörünün altında bulunan `package.json` dosyasında tanımlanır.

    ### **Package.json**

    - Projenin ismi, açıklaması ya da versiyonu gibi bilgilerin **JSON** veri tipi halinde tutulduğu bir yerel paket veri tabanı (local package database)'dır. 
    - Proje dizininde çalıştırılacak olan `npm init` komutu ile proje hakkındaki bilgilerin doldurulması gerekecektir. Sonra da komutun çalıştırıldığı dizinde `package.json` dosyası oluşacaktır.
    
        - Package.json dosyası oluşturulurken generator'ün varsayılan bilgileri kullanılması ve geliştiriciye soru sormaması için `-y` flag'ı kullanılabilir. Böylece proje hakkındaki diğer bilgiler gerektiği zaman güncellenebilir. 
        - `-y` flag'ı "yes" kelimesinin kısaltmasıdır.

    <br />

- **NPM** komutu ile kurulan paketler `global` ya da `local` olarak kurulur. Fakat ön tanımlı olarak kurulumlar `local` olarak gerçekleşir. Kurulumun `global` olarak gerçekleşmesi için "global" kelimesinin kısaltması olan `-g `flag'ı kullanılmalıdır.
    - `Global` olarak indirilen paketler isimleri ile çağrılır. Bu kurulum tercihi, projelerde sıklıkla kullanılacak paketler için tercih edilir. Fakat `global` olarak paket kurmanın bazı dezavantajları olabilir:
    
        - Proje geliştirme sürecinde bir paketin farklı versiyonlarına ihtiyaç olabilir. Fakat bir paketin `global` olarak tanımlanması buna engel olabilmektedir.
        - Geliştiricinin bulunduğu ya da yazmanın yapılacağı dizinde değişiklik yapma yetkisi olmayabilir. Bu da paketi kuramamasına yol açabilir.
        - `Global` paketler diskte tutulduğundan gereksiz yer kaplayabilir.

    <br />

    - Global olarak kurulan paket ya paketler proje dizini altında `./node_modules` klasörünü oluşturmayacak ya da bu klasör var ise klasörün içine kurulumu yapmayacaktır. Kurulum global olduğu için `/usr/local/lib/node_modules/{paket_ismi}` dizini içerisindeki node_modules klasörü altına paket kurulur. Fakat bu paketin proje içerisinde kullanılıdığını tanımlamak için kurulum yapılırken `--save` ya da `--save-dev` flag'leri kullanılmalıdır.

        ```
            npm install express -g --save-dev
        ```

        - `--save` flag'ı, paketin **production** kısmında gerekli olduğunu ve bundan dolayı `package.json` dosyası içerisinde `dependencies` key'i altına paket bilgilerini ekler.

        - `--save-dev`, paketin development ve test sürecinde gerekli olduğunu ve bundan dolayı paket bilgilerini devDependencies key'i altına ekler.

    - `Local` olarak kurulan paketler proje dizini içerisine kurulur. Bunun için de genellikle `./node_modules` klasörü oluşturulur. **Executable files** denilen yürütme dosyaları `./node_modules/.bin/` içerisinde tutulur. Bu kurulum tercihi sadece proje bağlamında kullanılacak paketler için yapılır. Local olarak yapılan paket kurulumları proje dizinindeki `./node_modules` klasörü içerine yapılır. Ayrıca `package.json` dosyasında `dependencies` key'inin value'sunda ilgili paketin ismi ve versiyonu görülebilir.

- Proje için gerekli olan paketlerin kurulmasının yanında istenen paket `npm uninstall {paket_adı}` komutu ile kaldırılabilir ya da `npm update {paket_adı}` komutu ile güncellenebilir. Ayrıca komutun çalıştırıldığı dizinde kurulu olan paketlerin listesini döndürmek için `npm list` komutu, kurulu olan paketlerin durumlarının öğrenmek için ise `npm outdated` komutu kullanılanılabilir.

- **NPM**'in alternatifi olarak kullanılabilecek [yarn](https://classic.yarnpkg.com/en/) gibi paket yönetim araçları bulunmaktadır. Bu tarz paket yönetim araçlarının geliştirmesi devam etmekle beraber, [bower](https://bower.io/) gibi araçların da geliştrilmesi askıya alınmıştır. Hangi aracın kullanılacağı size bağlıdır. Tercih sizin.

## NPX (**N**ode **P**ackage E**x**ecute)

- Bir paketin global olarak kullanılması çeşitli dezavantajları olabilir denmilmişti. Bundan dolayı NPM 5.2.0 versiyonuyla beraber NPX isimli bir araç tanıttı. Bu sayede bir paketi global olarak kurmadan çağırabiliyoruz.

    - `create-react-app` paketini kullanarak bir proje oluşturmak için önceden bu paketin global olarak kurulması ardından da çalıştırılması gerekmektedir.

    ``` 
        npm install -g create-react-app // paket kurulumu
        
        create-react-app first-app      // paketin çalıştırılması
    ```

    - **NPX** ile birlikte `create-react-app` paketini kullanarak bir proje oluşturmak için öncelikle NPX local'de bu paketin varlığını kontrol eder ve varsa çalıştırır yoksa da paketi indirdikten sonra çalıştırır.

    ```
        npx create-react-app first-app
    ```

- NPX bir paketi çalıştırmak için önce local'deki `./node_modules` klasörü içerisinde paketi arar, eğer paketi bulamazsa bu paketi kurar ve çalıştırır. Kurulan paket herhangi bir yerde de depolanmaz.

- `create-react-app` paketini kullanarak bir proje oluşturmak için önceden bu paketin global olarak kurulması ardından da çalıştırılması gerekmektedir.

## Named Export and Default Export

- `default` tag'ı olmadan yapılan `export` işlemleri **Named export**'dır. `default` tag'ı ile yapılan `export` işlemleri **Default export**'dır. Bu `export` işlemleri **React** ile değil **ES6** ile beraber gelen özelliklerdir. Fakat yine de **React** ekosistemine etkisi vardır.

- **Named exports**, tanımlayıcı(identifier) olarak fonksiyonun ya da class'ın ismini kullanır.

    - Named component'i `import` edebilmek için, `export` edilirken kullanılan isim kullanılır. İsimler ***küme parantezi*** içerisinde import edilmelidir.

    ```javascript
        import { component1, component2 } from "./my-components"
    ```
    - Bir component'in `export` edilen isim yerine farklı bir isimle `import` etmek istersek, konsoldan bu component'in bulunamadığını belirten bir hata mesajı döner. Bundan kurtulmak ve o component'i bakşa bir isim ile çağırmak istiyorsak **alias**(takma ad) kullanmalıyız. Takma ad kullanmak, `import` edilen dosyada bir **collisions**(çakışma) varsa onu engellemeye olanak sağlar.

    ```javascript
        import { component1, component1Alias } from "./my-component"
    ```

    - **Named export** ile bir dosya içerisinde birden fazla `export` işlemi yapılabilir. Bu işlem herhangi bir hataya sebep olmaz.

    ```javascript
        export const component1 = () => {};
        export const component2 = () => {};
        export const component3 = () => {};
    ```

     ```javascript
        import { component1, component2, component3 } from "./my-component"
    ```

    - Genellikle yardımcı bir UI component'i gibi birçok kez import edilecek bileşenler için **named export** kullanılır.

- **Default export**, `default` tag'ı kullanılarak yapılır. Genellikle sayfanın en altında görülse de istenilen yerde tanımlanabilir.

    - Default export kullanıldığında küme parantez kullanılmaz.

    ```javascript
        import component1 from "./my-component" 
    ```

    - **Named export**'tan farklı olarak **default export**, `import` edilirken istenilen isim ile çağrılabilir. Çünkü **default export** işlemi bir sayfa içerisinde ***sadece bir kez*** yapılabildiğinden hangi component'e ait olduğu bilinmektedir.

    ```javascript
        import WhateverNameIsBest from "./my-component" 
    ```

    - Genelde bir kez `import` edilecek ya da tek bir işleve sahip component'ler için **default export** kullanılır.

- Hem `default export` hem de `named export` işlemi tek bir sayfada farklı component'ler için tanımlanabilir. Ayrıca bu component'ler tek bir satırda `import` edilebir. React, buna en güzel örnektir.

    ```javascript
        import React, { useState, useEffect } from "react"
    ```

## React StrictMode

- StrictMode, React tarafından olası sorunları vurgulamak(highlighting) için geliştirmiş bir araçtır.

- React yönergelerine ve önerilen uygulamalara uyulmadığında görsel geri bildirim (uyarı/hata mesajları) sağlar.

- React StrictMode, UI'a bir etki etmez.

- React StrictMode, geliştiricilerin verimli bir şekilde kod yazmasını sağlayan ve yanlışlıkla uygulamaya eklenmiş olabilecek herhangi bir şüpheli kodu dikkatlerine sunan bir yardımcı bileşen olarak görülebilir. [[1]](https://www.geeksforgeeks.org/what-is-strictmode-in-react/#:~:text=StrictMode%20is%20a%20React%20Developer,warnings%20for%20its%20child%20components.)

- StrictMode bir geliştirici aracı olduğundan, yalnızca geliştirme modunda çalışır. Production yapısını hiçbir şekilde etkilemez.

- Kullanımdan kaldırılan ya da güvenli olmadığı kabul edilen eski lifecycle metotlarının kullanılmadığını doğrular ve aksi bir durumda konsoldan geliştiriciyi uyarır. Özellikle uygulama içerisinde kullanılan third-party kütüphanelerin bu metotları kullanıp kullanmadığını öğreniriz.

- Potansiyel riskleri belirleyerek bazı yan etkileri önlemeye yardımcı olur.

- Bu maddeleri daha iyi anlamak ve diğer özellikler hakkında bilgi sahibi olmak için [React dökümanını](https://tr.reactjs.org/docs/strict-mode.html) okuyabilirsiniz.

## Props

- Component'ler arası veri aktarımına olanak sağlayan **nesnelerdir**.

- "Properties" kelimesinin kısaltmasıdır.

- Prop'lar read-only'dir. Data, ana bileşenden alt bileşene gönderilirken herhangi bir değişime uğrayamaz. Kısacası prop'lar **immutable'dır**.

- Component'lere prop olarak istenilen isimde attribute eklenebilir.

- Prop'ları tanımlarken hangi veri tipini ya da tiplerinin kabul edildiğini component'e belirtmek için `Prop Types` kullanılır.

    ```jsx
        import PropTypes from "prop-types"

        function User({ name, surname, age, isLoggedIn, friends }) {
            return (
                <>
                    <h1>
                        {isLoggedIn ? `${name} ${surname} (${age})` : "Not logged in"}
                    </h1>

                    {friends.map((friend) => (
                        <div key={friend.id}>{friend.name}</div>
                    ))}
                </>
            )   
        }

        User.propTypes = {
            name: PropTypes.string,
            surname: PropTypes.string,
            isLoggedIn: PropTypes.bool,
            age: PropTypes.number,
            friends: PropTypes.array,
        }

        export default User
    ```

    - Component'leri tanımlarken bazı prop'ların boş gelmemesi önemli olabilir. Bundan dolayı boş bırakılması istenmeyen prop'ların tip tanımları yapılırken, prop'lara `isRequired` tanımı eklenmelidir.

        ```jsx
            import PropTypes from "prop-types"

            // ...

            User.propTypes = {
                name: PropTypes.string.isRequired,
                surname: PropTypes.string.isRequired,
                isLoggedIn: PropTypes.bool.isRequired,
                age: PropTypes.number.isRequired,
                friends: PropTypes.array,
            }

            // ...
        ```

    - Bir prop'a birden fazla veri tipi gönderilebilir. Bunun için ise `oneOfType` tanımı kullanılır.

        ```jsx
            import PropTypes from "prop-types"

            // ...

            User.propTypes = {
                name: PropTypes.string.isRequired,
                surname: PropTypes.string.isRequired,
                isLoggedIn: PropTypes.bool.isRequired,
                age: PropTypes.oneOfType([PropTypes.number, PropTypes.string]).isRequired,
                friends: PropTypes.array,
            }

            // ...
        ```
    
    - `Object` veri tipinde gönderilen prop'ların tip tanımları yapılırken `prop type` altında bulunan `shape` tanımı kullanılır. Böylece objelerin altındaki `key`'lerin her birinin tipi ayrı ayrı tanımlanabilir.

        ```jsx
            import PropTypes from "prop-types"

            // ...

            User.propTypes = {
                name: PropTypes.string.isRequired,
                surname: PropTypes.string.isRequired,
                isLoggedIn: PropTypes.bool.isRequired,
                age: PropTypes.oneOfType([PropTypes.number, PropTypes.string]).isRequired,
                address: PropTypes.shape({
                    title: PropTypes.string,
                    zip: PropTypes.number,
                }),
            }

            // ...
        ```

    - Herhangi bir tanım yapılmamış prop'lara `default`bir değer atanabilir. Kimi prop'ların boş değer ile dönmesindense varsayılan bir değer ile dönmesi tercih edilebilir. Bundan dolayı kullanımı önemlidir.

        ```jsx
            import PropTypes from "prop-types"

            // ...

            User.propTypes = {
                //...
            }

            User.defaultProps = {
                name: "Anonymous",
                isLoggedIn: false
            }

            // ...
        ```

## State

- Component'ler üzerinde değerinin değişme ihtimali olan bütün verileri tutan bir `Javascript` objesidir.

- Component'ler üzerinde değerinin değişme ihtimali olan bir veri `state` olarak tanımlanır. Bu `state` değiştiği anda da component render edilerek değişim ekranda gösterilir.

- Uygulama içerisinde `state` tanımlamak için, `react` kütüphanesi içerisindeki `useState` hook'u kullanılmalıdır.

    ``` jsx
        import { useState } from 'react' 

        function App() {
            const [name, setName] = useState("Jordan")

            return (
                <div className="App">
                    <h1>Hello {name}!</h1>
                    <button onClick={() => setName("Walke")}>Click</button>
                </div>
            )
        }
    ```

    - `State` tanımı yapılırken yukarıdaki kod bloğunda da görüldüğü gibi `useState` metodu çağırılarak yapılır. `[name, setName]` ataması ise; ilk değer state'in atanacağı değişkeni temsil ederken, ikinci
    değişken ise bu state değişkeninin değerini değiştiren fonksiyonu ismini temsil eder. 

        - `name` ve `setName` tanımı, genel yazım standardıdır. State'i değiştirecek fonksiyonun ismi, state'in değerini tutan değişkenin isminin başına "set" kelimesini alarak `camel-case` olarak tanımlanır.

        - `useState` hook'u çağırılırken içerisine state'in değeri default(varsayılan) olarak atanabilir. Yukarıdaki kod bloğunda da görüldüğü gibi `name` state'inin varsayılan değeri Jordan'dır.

    - `State` tanımı yapılırken Javascript'in izin verdiği bütün veri tipleri kullanılabilmektedir.

    - Herhangi bir `state` güncellendiği anda component'in render işlemi tekrar yapılmaktadır. Böylece arayüzdeki değişim state'in değiştiği anda ekrana yansıtılır. Render edilen kısım, `return` altındaki her şeydir. Ama bu da gereksiz render gibi sorunlara yol açabilmektedir.

- Herhangi bir `state`'e değer ataması yapılırken, o `state`'in veri tipi dikkate alınmalıdır. Özellikle `array` ya da `object` tipi state'lerde yapılan değer atamalarına dikkat edilmelidir.

    - `Array state`'lerde, set işlemi ile değer güncellemesi yapılırken var olan `array` kaybedilebilir ya da farklı bir veri tipine sahip değişken atanabilir.

        ```jsx
            import { useState } from 'react' 

            function App() {
                const [countries, setCountries] = useState(["Turkey", "Germany", "United States"])

                return (
                    <div className="App">
                        {countries.map((country, index) => (
                            <div key={index}>{country}</div>
                        ))}
                        <button onClick={() => setCountries ([...countries, "Cyprus"])}>Add new country</button>
                    </div>
                )
            }
        ```

        - Yukarıda da görüldüğü gibi `array state` güncellenirken var olan array `...countries` yapısındaki gibi korunur ve diğer değer üzerine eklenerek arayüz baştan render edilir.
        
    - `Object state`'lerde de, array state'lerde olduğu gibi güncelleme yapılırken var olan değerleri ve veri tipi korunmalıdır.

        ```jsx
            import { useState } from 'react' 

            function App() {
                const [address, setAddress] = useState({ country: "İstanbul", county: "Tuzla", zip: 34947})

                return (
                    <div className="App">
                        <div>
                            {address.country} {address.county} {address.zip}
                        </div>
                        <button onClick={() => setAddress ({ ...address, country: "Ankara", county: "Çankaya", zip: 06680 })}>Change new address</button>
                    </div>
                )
            }
        ```
        - Yukarıda da görüldüğü gibi `object state` güncellenirken var olan object `...address` yapısındaki gibi korunur ve diğer değer üzerine eklenerek arayüz baştan render edilir.

## Lifecycle

- Component'ler, `React.Component` nesnesinin temel bir sınıfıdır. Temel bir sınıf olduğu için, bu nesnenin bir alt sınıfı **extends** edilerek tanımlanr. 

    ```js
        class firstComponent extends React.Component{
            render() {
                return <h1>Hello World!</h1>;
            }
        }
    ```

    Ya da 

    ```js
        function Welcome(props) {
            return <h1>Hello, {props.name}</h1>;
        }
    ```

- React'ın önceki versiyonunda bu işlemler class component'ler ile yapılırken özel tanımlı fonksiyonlar vardı. React'ın yeni versiyonu ile birlikte lifecycle yapısı kullanılarak daha temiz bir kod yazılabiliyor.

- Her component'in **lifecycle** metotları vardır. Bu döngü, component'lerin oluşturulmasını(initialization), DOM'a bağlanmasını(mounting), DOM üzerinde güncellenmesini(updating) ve DOM üzerinden kaldırılması(unmount) ifade etmektedir. Örneğin, component'in istenilen bir anı yakalanarak ona göre veri çekme işlemi gerçekleştirilebilir. Bu sayede bir butona basmak ya da kullanıcı ile etkileşime girmeye gerek olmayabilir.

    - Component initialize edilirken ve DOM'a bağlanırken kullanılan 4 metot vardır. Bunlar:

        - `constructor()`: Başlangıç **state**'i tanımlamak ve bir fonksiyonu component'e bind etmek için en uygun yer constructor'dur. Bu iki tanımlamaya ihtiyac yoksa constructor metodu tanımlanmayabilir.

            ```js
            constructor(props) {
                super(props);
                this.state = {
                    date: new Date()
                };
            }
            ```

        - `componentWillMount()`:  Real DOM'a aktarılmadan önceki andır. Yani ``render`` işleminden hemen önceki tetiklenen Event’tir. Aynı **constructor** gibi özel tanımlı bir fonksiyondur.

        - `render()`: Bu metot, `React.Component` class'ı için olmazsa olmaz, çağrılmazsa sorun çıkaracak tek metottur.

        - `componentDidMount()`: Component DOM'a render edildikten sonra çalışan Event’dir. Yani render işleminden sonra çalışır. ComponentDidMount’ta `setState` işlemi yapılırsa tekrardan **Render** işlemi yapılır. 

    - Component mounting edilirken yani DOM'a bağlanırken kullanılan 4 metot vardır. Bunlar:

        - `componentWillReceiveProps()`: Eğer bir component'te props varsa ve bu props’u değiştirme işlemi yapıldığında tetiklenen event’tir.

        - `shouldComponentUpdate()`: Props veya state değiştiği anda component'in baştan render edilip edilmemesi gerektiği manual olarak belirlenebilir. Bu event, sadece boolen değer döndürür. True ise component baştan render edilir false ise render edilmez.

        - `componentWillUpdate()`: Yeni props veya state alındığında render edilmeden hemen önce çağrılır.

        - `componentDidUpdate()`: Güncelleme gerçekleştikten hemen sonra çağrılır. Bu fonksiyon ilk render için çağrılmaz.

    - Component unmounting edilirken yani DOM'dan kaldırılırken kullanılan 1 metot vardır. Bu:

        - `componentWillUnmount()`: Bir component unmounted veya destroyed edilmeden hemen önce çağrılır. Bu fonksiyonda, zamanlayıcıları geçersiz kılma, network isteklerini iptal etme veya componentDidMount() fonksiyonu ile oluşturulan abonelikleri temizleme gibi işlemler yapılabilir. Bunu unutma.

- **Lifecycle** metotları, **React** içerisine build-in olarak gelen `useEffect` hook'u sayesinde kullanılır. İlk parametre olarak, event gerçekleştiği anda ne olacağının tanımlandığı **callback** fonkiyonu alır; ikinci parametre olarak ise dependency array alır. Eğer bu array boş bırakılırsa component'in mount olma anı yakalanır. Ama bir state'in mount olma anı yakalanmak istenirse, array elemanı olarak state'in adı yazılmalıdır.

- React component'lerindeki gereksiz render'ları önlemek ve böylece component'in performansını artırmak için **memorizing** yöntemleri kullanılmaktadır. 

    - İlk kullanılan yöntem `React.memo`'dur. Bir container'ın içerisindeki state'de herhangi bir değişiklik olduğunda component'in içerisindeki bütün elementler tekrar render edileceği için, aşağıdaki örnekteki gibi "Header" component'i de baştan render edilecektir. Bu da "Header" component'inin gereksiz render'ına sebep olmaktadır.
    
        ```js
            import { useState } from "react"
            import Header from "./components/Header"

            function App() {
                const [number, setNumber] = useState(0)

                return (
                    <div className="App">
                        <Header />

                        <hr />

                        <h1>{number}</h1>
                        <button onClick={() => setNumber(number + 1)}>Click</button>
                    </div>
                )
            }

            export default App
        ```
        Bunu engellemek için de aşağıdaki gibi component `export` edilirken `React.memo` ile sarmalanmalıdır. Böylece state değiştiğinde, return altındaki Header elementi de gereksiz yere `render` edilmeyecektir. Fakat Header component'ine prop olarak state değişkeni verilirse `render` işlemi tekrardan onu da kapsar.

        ```js
            // Header component
            function Header() {
                return  <div>Header</div>;
            }

            export default React.memo(Header);
        ```
    
    - Kullanılabilecek ikinci yöntem `useMemo` hook'udur. `useEffect` hook'u ile aynı kullanıma sahiptir. İlk parametre olarak **callback** fonksiyonu, ikinci parametre olarak da **dependency array** alır. 
    
        - `React.memo` ile sarmalanan bir component'e gönderilen prop'lar değişmediği sürece **re-render** edilmezdi. Bu doğru. Fakat göderilen prop değişkeninin tipi `object` ya da `array` olduğunda, her render işleminde bu değişkenler tekrar tanımlanacağından hafızadaki adresleri değişecektir. Bu da, React.memo'nun prop değişkeninin değiştiğini düşenmesine sebep olarak component'in tekrar render edilmesine sebep olacaktır. Bu nedenle `useMemo` hook'u kullanılır.

            - Javascript ile tanımlanan her object ya da array değişkenlerinin bellek üzerindeki referansları farklıdır. Aşağıdaki örnekteki gibi iki boş object değişkeni birbirine eşit değildir. Çünkü bellekteki adresleri farklıdır. Aynısı array tipi değişkenler için de geçerlidir.

                ```js
                {} === {}
                // return false
                    
                [] === []
                // return false
                ```
            
            Örnek kullanımı aşağıdaki gibidir. Dependency array olarak verilecek değişken ile de, o değişken her değiştiğinde Header değişkeni de re-render edilir.
            ```js
                import { useState } from "react"
                import Header from "./components/Header"

                function App() {
                    const [number, setNumber] = useState(0)

                    const data = useMemo(() => {
                        return { name: "Abdullah" }
                    }, [])

                    return (
                        <div className="App">
                            <Header data={data} />

                            <hr />

                            <h1>{number}</h1>
                            <button onClick={() => setNumber(number + 1)}>Click</button>
                        </div>
                    )
                }

                export default App
            ```
    
    - Üçüncü yöntem ise `useCallback` hook'u. `useMemo` nun aksine aldığı işlevin sonucunu saklamak yerine işlevin kendisini saklar. `Dependency` olarak verilen değerleri değişmediği sürece de sakladığı işlevi döndürür.

        - Bunun faydası, compenent içerisinde tanımlanan işlevler, o component yeniden `render` edildiğinde yeniden tanımlanır ve farklı bir referansa sahip olur. Bu yüzden bu işlevler `props` olarak iletildiğinde aslında işlev değişmemesine rağmen iletildiği bileşenin yeniden `render` edilmesine neden olurlar.

        ```js
            import { useState, useCallback } from "react"
            import Header from "./components/Header"

            function App() {
                const [number, setNumber] = useState(0)

                const increment = useCallback(() => {
                    setNumber((prevState) => prevState + 1)
                }, [])

                return (
                    <div className="App">
                        <Header increment={increment} />

                        <hr />

                        <h1>{number}</h1>
                    </div>
                )
            }

            export default App
        ```

        ```js
            // Header component
            function Header({ increment }) {
                return  (
                    <div>
                        Header
                        <button onClick={increment}></button>
                    </div>;
                )
            }

            export default React.memo(Header);
        ```

## Context API
