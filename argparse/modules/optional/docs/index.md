# Header file `optional.hpp`<a id="optional.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_optional.html#optional.hpp'>TL_OPTIONAL_HPP</a>

#define <a href='doc_optional.html#optional.hpp'>TL_OPTIONAL_VERSION_MAJOR</a>

#define <a href='doc_optional.html#optional.hpp'>TL_OPTIONAL_VERSION_MINOR</a>

#define <a href='doc_optional.html#optional.hpp'>IS_TRIVIALLY_COPY_CONSTRUCTIBLE</a>(T)

#define <a href='doc_optional.html#optional.hpp'>IS_TRIVIALLY_COPY_ASSIGNABLE</a>(T)

#define <a href='doc_optional.html#optional.hpp'>IS_TRIVIALLY_DESTRUCTIBLE</a>(T)

#define <a href='doc_optional.html#optional.hpp'>TL_OPTIONAL_CXX14</a>

#define <a href='doc_optional.html#optional.hpp'>TL_MONOSTATE_INPLACE_MUTEX</a>

#define <a href='doc_optional.html#optional.hpp'>TL_TRAITS_MUTEX</a>

namespace <a href='doc_optional.html#optional.hpp'>tl</a>
{
    class <a href='doc_optional.html#tl::monostate'>monostate</a>;
    
    struct <a href='doc_optional.html#tl::in_place_t'>in_place_t</a>;
    
    constexpr <a href='doc_optional.html#tl::in_place_t'>in_place_t{}</a> <a href='doc_optional.html#tl::in_place'>in_place</a>;
    
    struct <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>;
    
    static constexpr nullopt_t nullopt;
    
    class <a href='doc_optional.html#optional.hpp'>bad_optional_access</a>;
    
    template &lt;class T&gt;
    class <a href='doc_optional.html#tl::optional-T-'>optional</a>;
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator==</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator!=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&lt;</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&gt;</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&lt;=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&gt;=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator==</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator==</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator!=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator!=</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;=</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;=</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator==</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator==</a>(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator!=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator!=</a>(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&lt;</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&lt;</a>(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&lt;=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&lt;=</a>(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&gt;</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&gt;</a>(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&gt;=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.html#tl::operator==(constoptional-T-&,constU&)'>operator&gt;=</a>(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T&gt;
    void swap(optional&lt;T&gt; &amp;lhs, optional&lt;T&gt; &amp;rhs);
    
    namespace <a href='doc_optional.html#optional.hpp'>detail</a>
    {
        struct <a href='doc_optional.html#optional.hpp'>i_am_secret</a>;
    }
    
    template &lt;class T = detail::i_am_secret, class U, class Ret = detail::conditional_t&lt;std::is_same&lt;T, detail::i_am_secret&gt;::value, detail::decay_t&lt;U&gt;, T&gt;&gt;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional&lt;Ret&gt;</a> <a href='doc_optional.html#optional.hpp'>make_optional</a>(U&amp;&amp; v);
    
    template &lt;class T, class ... Args&gt;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.html#optional.hpp'>make_optional</a>(Args&amp;&amp;... args);
    
    template &lt;class T, class U, class ... Args&gt;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.html#optional.hpp'>make_optional</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args);
    
    template &lt;class T&gt;
    class <a href='doc_optional.html#tl::optional-T&-'>optional&lt;T&amp;&gt;</a>;
}

namespace <a href='doc_optional.html#optional.hpp'>std</a>
{
}</code></pre>

## Class `tl::monostate`<a id="tl::monostate"></a>

<pre><code class="language-cpp">class monostate
{
};</code></pre>

Used to represent an optional with no data; essentially a bool

## Struct `tl::in_place_t`<a id="tl::in_place_t"></a>

<pre><code class="language-cpp">struct in_place_t
{
    <a href='doc_optional.html#tl::in_place_t'>in_place_t</a>() = default;
};</code></pre>

A tag type to tell optional to construct its value in-place

## Variable `tl::in_place`<a id="tl::in_place"></a>

<pre><code class="language-cpp">constexpr <a href='doc_optional.html#tl::in_place_t'>in_place_t{}</a> in_place;</code></pre>

A tag to tell optional to construct its value in-place

## Struct `tl::nullopt_t`<a id="tl::nullopt_t"></a>

<pre><code class="language-cpp">struct nullopt_t
{
    struct <a href='doc_optional.html#tl::nullopt_t'>do_not_use</a>;
    
    constexpr <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>(<a href='doc_optional.html#tl::nullopt_t'>do_not_use</a>, <a href='doc_optional.html#tl::nullopt_t'>do_not_use</a>) noexcept;
};</code></pre>

A tag type to represent an empty optional

## Variable `tl::nullopt`<a id="tl::nullopt"></a>

<pre><code class="language-cpp">static constexpr nullopt_t nullopt;</code></pre>

Represents an empty optional

*Examples*:

    tl::optional<int> a = tl::nullopt;
    void foo (tl::optional<int>);
    foo(tl::nullopt); //pass an empty optional

## Class template `tl::optional`<a id="tl::optional-T-"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
class optional
{
public:
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) &amp;;
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) const &amp;;
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) const &amp;&amp;;
    
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;;
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;;
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;&amp;;
    
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;
    
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u) &amp;;
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)
    
    template &lt;class U&gt;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional&lt;typename std::decay&lt;U&gt;::type&gt;</a> <a href='doc_optional.html#tl::optional-T-::conjunction(U&&)const'>conjunction</a>(U&amp;&amp; u) const;
    
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;&amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;&amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;&amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::disjunction(constoptional-T-&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;&amp;;
    
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::take()&'>take</a>() &amp;;
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::take()&'>take</a>() const &amp;;
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::take()&'>take</a>() &amp;&amp;;
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T-::take()&'>take</a>() const &amp;&amp;;
    
    using <a href='doc_optional.html#tl::optional-T-'>value_type</a> = T;
    
    constexpr <a href='doc_optional.html#tl::optional-T-::optional()'>optional</a>() noexcept = default;
    constexpr <a href='doc_optional.html#tl::optional-T-::optional()'>optional</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    
    constexpr <a href='doc_optional.html#tl::optional-T-::optional(constoptional-T-&)'>optional</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) = default;
    
    constexpr <a href='doc_optional.html#tl::optional-T-::optional(optional-T-&&)'>optional</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) = default;
    
    template &lt;class... Args&gt; constexpr explicit optional(in_place_t, Args&amp;&amp;... args);
    template &lt;class U, class... Args&gt;
    constexpr explicit optional(in_place_t, std::initializer_list&lt;U&gt;&amp;, Args&amp;&amp;... args);
    
    template &lt;class U=T&gt; constexpr optional(U &amp;&amp;u);
    
    template &lt;class U&gt; optional(const optional&lt;U&gt; &amp;rhs);
    
    template &lt;class U&gt; optional(optional&lt;U&gt; &amp;&amp;rhs);
    
    <a href='doc_optional.html#tl::optional-T-::~optional()'>~optional</a>() = default;
    
    <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.html#tl::optional-T-::operator=(tl::nullopt_t)'>operator=</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    
    <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.html#tl::optional-T-::operator=(constoptional-T-&)'>operator=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) = default;
    
    <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.html#tl::optional-T-::operator=(optional-T-&&)'>operator=</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) = default;
    
    optional &amp;operator=(U &amp;&amp;u);
    
    optional &amp;operator=(const optional&lt;U&gt; &amp; rhs);
    
    optional &amp;operator=(optional&lt;U&gt; &amp;&amp; rhs);
    
    template &lt;class ... Args&gt;
    T&amp; <a href='doc_optional.html#tl::optional-T-::emplace(Args&&...)'>emplace</a>(Args&amp;&amp;... args);
    template &lt;class U, class... Args&gt;
    T&amp; emplace(std::initializer_list&lt;U&gt; il, Args &amp;&amp;... args);
    
    void <a href='doc_optional.html#tl::optional-T-::swap(optional-T-&)'>swap</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) noexcept(std::is_nothrow_move_constructible&lt;T&gt;::value&amp;&amp;detail::is_nothrow_swappable&lt;T&gt;::value);
    
    constexpr const T *operator-&gt;() const;
    constexpr T *operator-&gt;();
    
    constexpr T &amp;operator*();
    constexpr const T &amp;operator*() const;
    
    constexpr bool <a href='doc_optional.html#tl::optional-T-::has_value()const'>has_value</a>() const noexcept;
    constexpr <a href='doc_optional.html#tl::optional-T-::has_value()const'>operator bool</a>() const noexcept;
    
    constexpr T &amp;value();
    constexpr const T &amp;value() const;
    
    template &lt;class U&gt;
    constexpr T <a href='doc_optional.html#tl::optional-T-::value_or(U&&)const&'>value_or</a>(U&amp;&amp; u) const &amp;;
    template &lt;class U&gt;
    constexpr T <a href='doc_optional.html#tl::optional-T-::value_or(U&&)const&'>value_or</a>(U&amp;&amp; u) &amp;&amp;;
    
    void <a href='doc_optional.html#tl::optional-T-::reset()'>reset</a>() noexcept;
};</code></pre>

An optional object is an object that contains the storage for another object and manages the lifetime of this contained object, if any. The contained object may be initialized after the optional object has been initialized, and may be destroyed before the optional object has been destroyed. The initialization state of the contained object is tracked by the optional object.

### Function template `tl::optional::and_then`<a id="tl::optional-T-::and_then(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) &amp;&amp;;

(3)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) const &amp;;

(4)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) const &amp;&amp;;</code></pre>

Carries out some operation which returns an optional on the stored object if there is one. \\requires `std::invoke(std::forward<F>(f), value())` returns a `std::optional<U>` for some `U`. \\returns Let `U` be the result of `std::invoke(std::forward<F>(f), value())`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise the return value of `std::invoke(std::forward<F>(f), value())` is returned.

### Function template `tl::optional::map`<a id="tl::optional-T-::map(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;&amp;;

(3)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;;

(4)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;&amp;;</code></pre>

Carries out some operation on the stored object if there is one.

*Returns*: Let `U` be the result of `std::invoke(std::forward<F>(f), value())`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise an `optional<U>` is constructed from the return value of `std::invoke(std::forward<F>(f), value())` and is returned.

### Function template `tl::optional::or_else`<a id="tl::optional-T-::or_else(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;&amp;;

(3)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;;</code></pre>

Calls `f` if the optional is empty

*Requires*: `std::invoke_result_t<F>` must be void or convertible to `optional<T>`.

*Effects*: If `*this` has a value, returns `*this`. Otherwise, if `f` returns `void`, calls `std::forward<F>(f)` and returns `std::nullopt`. Otherwise, returns `std::forward<F>(f)()`.

### Function template `tl::optional::map_or`<a id="tl::optional-T-::map_or(F&&,U&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) &amp;;

(2)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;

(3)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) const &amp;;

(4)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;</code></pre>

Maps the stored value with `f` if there is one, otherwise returns `u`.

If there is a value stored, then `f` is called with `**this` and the value is returned. Otherwise `u` is returned.

### Function template `tl::optional::map_or_else`<a id="tl::optional-T-::map_or_else(F&&,U&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u) &amp;;

(2)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)

(3)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)

(4)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)</code></pre>

Maps the stored value with `f` if there is one, otherwise calls `u` and returns the result.

If there is a value stored, then `f` is called with `**this` and the value is returned. Otherwise `std::forward<U>(u)()` is returned.

### Function template `tl::optional::conjunction`<a id="tl::optional-T-::conjunction(U&&)const"></a>

<pre><code class="language-cpp">template &lt;class U&gt;
constexpr <a href='doc_optional.html#tl::optional-T-'>optional&lt;typename std::decay&lt;U&gt;::type&gt;</a> conjunction(U&amp;&amp; u) const;</code></pre>

*Returns*: `u` if `*this` has a value, otherwise an empty optional.

### Function `tl::optional::disjunction`<a id="tl::optional-T-::disjunction(constoptional-T-&)&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;;

(2)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;;

(3)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;&amp;;

(4)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;&amp;;

(5)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;;

(6)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;;

(7)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;&amp;;

(8)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;&amp;;</code></pre>

*Returns*: `rhs` if `*this` is empty, otherwise the current value.

### Function `tl::optional::take`<a id="tl::optional-T-::take()&"></a>

<pre><code class="language-cpp">(1)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() &amp;;

(2)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() const &amp;;

(3)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() &amp;&amp;;

(4)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() const &amp;&amp;;</code></pre>

Takes the value out of the optional, leaving it empty

### Default constructor `tl::optional::optional`<a id="tl::optional-T-::optional()"></a>

<pre><code class="language-cpp">(1)  constexpr optional() noexcept = default;

(2)  constexpr optional(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;</code></pre>

Constructs an optional that does not contain a value.

### Copy constructor `tl::optional::optional`<a id="tl::optional-T-::optional(constoptional-T-&)"></a>

<pre><code class="language-cpp">constexpr optional(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) = default;</code></pre>

Copy constructor

If `rhs` contains a value, the stored value is direct-initialized with it. Otherwise, the constructed optional is empty.

### Move constructor `tl::optional::optional`<a id="tl::optional-T-::optional(optional-T-&&)"></a>

<pre><code class="language-cpp">constexpr optional(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) = default;</code></pre>

Move constructor

If `rhs` contains a value, the stored value is direct-initialized with it. Otherwise, the constructed optional is empty.

### Function template `tl::optional::optional`<a id="tl::optional-T-::optional(detail::enable_if_t-std::is_constructible-T,Args...-::value,in_place_t-,Args&&...)"></a>

<pre><code class="language-cpp">(1)  template &lt;class... Args&gt; constexpr explicit optional(in_place_t, Args&amp;&amp;... args);

(2)  template &lt;class U, class... Args&gt;
     constexpr explicit optional(in_place_t, std::initializer_list&lt;U&gt;&amp;, Args&amp;&amp;... args);</code></pre>

Constructs the stored value in-place using the given arguments.

### Function template `tl::optional::optional`<a id="tl::optional-T-::optional(U&&)"></a>

<pre><code class="language-cpp">template &lt;class U=T&gt; constexpr optional(U &amp;&amp;u);</code></pre>

Constructs the stored value with `u`.

### Function template `tl::optional::optional`<a id="tl::optional-T-::optional(constoptional-U-&)"></a>

<pre><code class="language-cpp">template &lt;class U&gt; optional(const optional&lt;U&gt; &amp;rhs);</code></pre>

Converting copy constructor.

### Function template `tl::optional::optional`<a id="tl::optional-T-::optional(optional-U-&&)"></a>

<pre><code class="language-cpp">template &lt;class U&gt; optional(optional&lt;U&gt; &amp;&amp;rhs);</code></pre>

Converting move constructor.

### Destructor `tl::optional::~optional`<a id="tl::optional-T-::~optional()"></a>

<pre><code class="language-cpp">~optional() = default;</code></pre>

Destroys the stored value if there is one.

### Assignment operator `tl::optional::operator=`<a id="tl::optional-T-::operator=(tl::nullopt_t)"></a>

<pre><code class="language-cpp"><a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; operator=(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;</code></pre>

Assignment to empty.

Destroys the current value if there is one.

### Assignment operator `tl::optional::operator=`<a id="tl::optional-T-::operator=(constoptional-T-&)"></a>

<pre><code class="language-cpp"><a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; operator=(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) = default;</code></pre>

Copy assignment.

Copies the value from `rhs` if there is one. Otherwise resets the stored value in `*this`.

### Assignment operator `tl::optional::operator=`<a id="tl::optional-T-::operator=(optional-T-&&)"></a>

<pre><code class="language-cpp"><a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; operator=(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) = default;</code></pre>

Move assignment.

Moves the value from `rhs` if there is one. Otherwise resets the stored value in `*this`.

### Assignment operator `tl::optional::operator=`<a id="tl::optional-T-::operator=(U&&)"></a>

<pre><code class="language-cpp">optional &amp;operator=(U &amp;&amp;u);</code></pre>

Assigns the stored value from `u`, destroying the old value if there was one.

### Assignment operator `tl::optional::operator=`<a id="tl::optional-T-::operator=(constoptional-U-&)"></a>

<pre><code class="language-cpp">optional &amp;operator=(const optional&lt;U&gt; &amp; rhs);</code></pre>

Converting copy assignment operator.

Copies the value from `rhs` if there is one. Otherwise resets the stored value in `*this`.

### Assignment operator `tl::optional::operator=`<a id="tl::optional-T-::operator=(optional-U-&&)"></a>

<pre><code class="language-cpp">optional &amp;operator=(optional&lt;U&gt; &amp;&amp; rhs);</code></pre>

Converting move assignment operator.

Moves the value from `rhs` if there is one. Otherwise resets the stored value in `*this`.

### Function template `tl::optional::emplace`<a id="tl::optional-T-::emplace(Args&&...)"></a>

<pre><code class="language-cpp">(1)  template &lt;class ... Args&gt;
     T&amp; emplace(Args&amp;&amp;... args);

(2)  template &lt;class U, class... Args&gt;
     T&amp; emplace(std::initializer_list&lt;U&gt; il, Args &amp;&amp;... args);</code></pre>

Constructs the value in-place, destroying the current one if there is one.

### Function `tl::optional::swap`<a id="tl::optional-T-::swap(optional-T-&)"></a>

<pre><code class="language-cpp">void swap(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) noexcept(std::is_nothrow_move_constructible&lt;T&gt;::value&amp;&amp;detail::is_nothrow_swappable&lt;T&gt;::value);</code></pre>

Swaps this optional with the other.

If neither optionals have a value, nothing happens. If both have a value, the values are swapped. If one has a value, it is moved to the other and the movee is left valueless.

### Operator `tl::optional::operator->`<a id="tl::optional-T-::operator--()const"></a>

<pre><code class="language-cpp">(1)  constexpr const T *operator-&gt;() const;

(2)  constexpr T *operator-&gt;();</code></pre>

*Returns*: a pointer to the stored value

*Requires*: a value is stored

### Operator `tl::optional::operator*`<a id="tl::optional-T-::operator*()&"></a>

<pre><code class="language-cpp">(1)  constexpr T &amp;operator*();

(2)  constexpr const T &amp;operator*() const;</code></pre>

*Returns*: the stored value

*Requires*: a value is stored

### Function `tl::optional::has_value`<a id="tl::optional-T-::has_value()const"></a>

<pre><code class="language-cpp">(1)  constexpr bool has_value() const noexcept;

(2)  constexpr operator bool() const noexcept;</code></pre>

*Returns*: whether or not the optional has a value

### Function `tl::optional::value`<a id="tl::optional-T-::value()&"></a>

<pre><code class="language-cpp">(1)  constexpr T &amp;value();

(2)  constexpr const T &amp;value() const;</code></pre>

*Returns*: the contained value if there is one, otherwise throws \[bad\_optional\_access\]

### Function template `tl::optional::value_or`<a id="tl::optional-T-::value_or(U&&)const&"></a>

<pre><code class="language-cpp">(1)  template &lt;class U&gt;
     constexpr T value_or(U&amp;&amp; u) const &amp;;

(2)  template &lt;class U&gt;
     constexpr T value_or(U&amp;&amp; u) &amp;&amp;;</code></pre>

*Returns*: the stored value if there is one, otherwise returns `u`

### Function `tl::optional::reset`<a id="tl::optional-T-::reset()"></a>

<pre><code class="language-cpp">void reset() noexcept;</code></pre>

Destroys the stored value if one exists, making the optional empty

-----

## Comparison operator `tl::operator==`<a id="tl::operator==(constoptional-T-&,constoptional-U-&)"></a>

<pre><code class="language-cpp">(1)  template &lt;class T, class U&gt;
     constexpr bool operator==(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(2)  template &lt;class T, class U&gt;
     constexpr bool operator!=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(3)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(4)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(5)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(6)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);</code></pre>

Compares two optional objects

If both optionals contain a value, they are compared with `T`s relational operators. Otherwise `lhs` and `rhs` are equal only if they are both empty, and `lhs` is less than `rhs` only if `rhs` is empty and `lhs` is not.

## Comparison operator `tl::operator==`<a id="tl::operator==(constoptional-T-&,tl::nullopt_t)"></a>

<pre><code class="language-cpp">(1)  template &lt;class T&gt;
     constexpr bool operator==(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;

(2)  template &lt;class T&gt;
     constexpr bool operator==(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;

(3)  template &lt;class T&gt;
     constexpr bool operator!=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;

(4)  template &lt;class T&gt;
     constexpr bool operator!=(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;

(5)  template &lt;class T&gt;
     constexpr bool operator&lt;(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;

(6)  template &lt;class T&gt;
     constexpr bool operator&lt;(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;

(7)  template &lt;class T&gt;
     constexpr bool operator&lt;=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;

(8)  template &lt;class T&gt;
     constexpr bool operator&lt;=(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;

(9)  template &lt;class T&gt;
     constexpr bool operator&gt;(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;

(10)  template &lt;class T&gt;
     constexpr bool operator&gt;(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;

(11)  template &lt;class T&gt;
     constexpr bool operator&gt;=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;

(12)  template &lt;class T&gt;
     constexpr bool operator&gt;=(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;</code></pre>

Compares an optional to a `nullopt`

Equivalent to comparing the optional to an empty optional

## Comparison operator `tl::operator==`<a id="tl::operator==(constoptional-T-&,constU&)"></a>

<pre><code class="language-cpp">(1)  template &lt;class T, class U&gt;
     constexpr bool operator==(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(2)  template &lt;class T, class U&gt;
     constexpr bool operator==(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(3)  template &lt;class T, class U&gt;
     constexpr bool operator!=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(4)  template &lt;class T, class U&gt;
     constexpr bool operator!=(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(5)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(6)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(7)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(8)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;=(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(9)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(10)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(11)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(12)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;=(const U&amp; lhs, const <a href='doc_optional.html#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);</code></pre>

Compares the optional with a value.

If the optional has a value, it is compared with the other value using `T`s relational operators. Otherwise, the optional is considered less than the value.

## Class template `tl::optional<T&>`<a id="tl::optional-T&-"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
class optional&lt;T&amp;&gt;
{
public:
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) &amp;;
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) const &amp;;
    template &lt;class F&gt;
    constexpr auto and_then(F &amp;&amp;f) const &amp;&amp;;
    
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;;
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;;
    template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;&amp;;
    
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T&-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T&-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T&-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.html#tl::optional-T&-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;
    
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u) &amp;;
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)
    template &lt;class F, class U&gt;
    auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)
    
    template &lt;class U&gt;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional&lt;typename std::decay&lt;U&gt;::type&gt;</a> <a href='doc_optional.html#tl::optional-T&-::conjunction(U&&)const'>conjunction</a>(U&amp;&amp; u) const;
    
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;&amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;&amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;&amp;;
    constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::disjunction(constoptional&)&'>disjunction</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;&amp;;
    
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::take()&'>take</a>() &amp;;
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::take()&'>take</a>() const &amp;;
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::take()&'>take</a>() &amp;&amp;;
    <a href='doc_optional.html#tl::optional-T-'>optional</a> <a href='doc_optional.html#tl::optional-T&-::take()&'>take</a>() const &amp;&amp;;
    
    using <a href='doc_optional.html#tl::optional-T&-'>value_type</a> = T&amp;;
    
    constexpr <a href='doc_optional.html#tl::optional-T&-::optional()'>optional</a>() noexcept;
    constexpr <a href='doc_optional.html#tl::optional-T&-::optional()'>optional</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    
    constexpr <a href='doc_optional.html#tl::optional-T&-::optional(constoptional&)'>optional</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) noexcept = default;
    
    constexpr <a href='doc_optional.html#tl::optional-T&-::optional(optional&&)'>optional</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) = default;
    
    template &lt;class U=T&gt; constexpr optional(U &amp;&amp;u);
    
    <a href='doc_optional.html#tl::optional-T&-::~optional()'>~optional</a>() = default;
    
    <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.html#tl::optional-T&-::operator=(tl::nullopt_t)'>operator=</a>(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;
    
    <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.html#tl::optional-T&-::operator=(constoptional&)'>operator=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) = default;
    
    optional &amp;operator=(U &amp;&amp;u);
    
    template &lt;class U&gt;
    <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.html#tl::optional-T&-::operator=(constoptional-U-&)'>operator=</a>(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class ... Args&gt;
    T&amp; <a href='doc_optional.html#tl::optional-T&-::emplace(Args&&...)'>emplace</a>(Args&amp;&amp;... args) noexcept;
    
    void <a href='doc_optional.html#tl::optional-T&-::swap(optional&)'>swap</a>(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) noexcept;
    
    constexpr const T *operator-&gt;() const;
    constexpr T *operator-&gt;();
    
    constexpr T &amp;operator*();
    constexpr const T &amp;operator*() const;
    
    constexpr bool <a href='doc_optional.html#tl::optional-T&-::has_value()const'>has_value</a>() const noexcept;
    constexpr <a href='doc_optional.html#tl::optional-T&-::has_value()const'>operator bool</a>() const noexcept;
    
    constexpr T&amp; <a href='doc_optional.html#tl::optional-T&-::value()&'>value</a>() &amp;;
    constexpr const T &amp;value() const;
    
    template &lt;class U&gt;
    constexpr T <a href='doc_optional.html#tl::optional-T&-::value_or(U&&)const&'>value_or</a>(U&amp;&amp; u) const &amp;;
    template &lt;class U&gt;
    constexpr T <a href='doc_optional.html#tl::optional-T&-::value_or(U&&)const&'>value_or</a>(U&amp;&amp; u) &amp;&amp;;
    
    void <a href='doc_optional.html#tl::optional-T&-::reset()'>reset</a>() noexcept;
};</code></pre>

Specialization for when `T` is a reference. `optional<T&>` acts similarly to a `T*`, but provides more operations and shows intent more clearly.

*Examples*:

    int i = 42;
    tl::optional<int&> o = i;
    *o == 42; //true
    i = 12;
    *o = 12; //true
    &*o == &i; //true

Assignment has rebind semantics rather than assign-through semantics:

    int j = 8;
    o = j;
    
    &*o == &j; //true

### Function template `tl::optional<T&>::and_then`<a id="tl::optional-T&-::and_then(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) &amp;&amp;;

(3)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) const &amp;;

(4)  template &lt;class F&gt;
     constexpr auto and_then(F &amp;&amp;f) const &amp;&amp;;</code></pre>

Carries out some operation which returns an optional on the stored object if there is one. \\requires `std::invoke(std::forward<F>(f), value())` returns a `std::optional<U>` for some `U`. \\returns Let `U` be the result of `std::invoke(std::forward<F>(f), value())`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise the return value of `std::invoke(std::forward<F>(f), value())` is returned.

### Function template `tl::optional<T&>::map`<a id="tl::optional-T&-::map(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) &amp;&amp;;

(3)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;;

(4)  template &lt;class F&gt; constexpr auto map(F &amp;&amp;f) const&amp;&amp;;</code></pre>

Carries out some operation on the stored object if there is one.

*Returns*: Let `U` be the result of `std::invoke(std::forward<F>(f), value())`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise an `optional<U>` is constructed from the return value of `std::invoke(std::forward<F>(f), value())` and is returned.

### Function template `tl::optional<T&>::or_else`<a id="tl::optional-T&-::or_else(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;&amp;;

(3)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;;</code></pre>

Calls `f` if the optional is empty

*Requires*: `std::invoke_result_t<F>` must be void or convertible to `optional<T>`. \\effects If `*this` has a value, returns `*this`. Otherwise, if `f` returns `void`, calls `std::forward<F>(f)` and returns `std::nullopt`. Otherwise, returns `std::forward<F>(f)()`.

### Function template `tl::optional<T&>::map_or`<a id="tl::optional-T&-::map_or(F&&,U&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) &amp;;

(2)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;

(3)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) const &amp;;

(4)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;</code></pre>

Maps the stored value with `f` if there is one, otherwise returns `u`.

If there is a value stored, then `f` is called with `**this` and the value is returned. Otherwise `u` is returned.

### Function template `tl::optional<T&>::map_or_else`<a id="tl::optional-T&-::map_or_else(F&&,U&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u) &amp;;

(2)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)

(3)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)

(4)  template &lt;class F, class U&gt;
     auto map_or_else(F &amp;&amp;f, U &amp;&amp;u)</code></pre>

Maps the stored value with `f` if there is one, otherwise calls `u` and returns the result.

If there is a value stored, then `f` is called with `**this` and the value is returned. Otherwise `std::forward<U>(u)()` is returned.

### Function template `tl::optional<T&>::conjunction`<a id="tl::optional-T&-::conjunction(U&&)const"></a>

<pre><code class="language-cpp">template &lt;class U&gt;
constexpr <a href='doc_optional.html#tl::optional-T-'>optional&lt;typename std::decay&lt;U&gt;::type&gt;</a> conjunction(U&amp;&amp; u) const;</code></pre>

*Returns*: `u` if `*this` has a value, otherwise an empty optional.

### Function `tl::optional<T&>::disjunction`<a id="tl::optional-T&-::disjunction(constoptional&)&"></a>

<pre><code class="language-cpp">(1)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;;

(2)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;;

(3)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) &amp;&amp;;

(4)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) const &amp;&amp;;

(5)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;;

(6)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;;

(7)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) &amp;&amp;;

(8)  constexpr <a href='doc_optional.html#tl::optional-T-'>optional</a> disjunction(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) const &amp;&amp;;</code></pre>

*Returns*: `rhs` if `*this` is empty, otherwise the current value.

### Function `tl::optional<T&>::take`<a id="tl::optional-T&-::take()&"></a>

<pre><code class="language-cpp">(1)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() &amp;;

(2)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() const &amp;;

(3)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() &amp;&amp;;

(4)  <a href='doc_optional.html#tl::optional-T-'>optional</a> take() const &amp;&amp;;</code></pre>

Takes the value out of the optional, leaving it empty

### Default constructor `tl::optional<T&>::optional`<a id="tl::optional-T&-::optional()"></a>

<pre><code class="language-cpp">(1)  constexpr optional() noexcept;

(2)  constexpr optional(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;</code></pre>

Constructs an optional that does not contain a value.

### Copy constructor `tl::optional<T&>::optional`<a id="tl::optional-T&-::optional(constoptional&)"></a>

<pre><code class="language-cpp">constexpr optional(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) noexcept = default;</code></pre>

Copy constructor

If `rhs` contains a value, the stored value is direct-initialized with it. Otherwise, the constructed optional is empty.

### Move constructor `tl::optional<T&>::optional`<a id="tl::optional-T&-::optional(optional&&)"></a>

<pre><code class="language-cpp">constexpr optional(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp;&amp; rhs) = default;</code></pre>

Move constructor

If `rhs` contains a value, the stored value is direct-initialized with it. Otherwise, the constructed optional is empty.

### Function template `tl::optional<T&>::optional`<a id="tl::optional-T&-::optional(U&&)"></a>

<pre><code class="language-cpp">template &lt;class U=T&gt; constexpr optional(U &amp;&amp;u);</code></pre>

Constructs the stored value with `u`.

### Destructor `tl::optional<T&>::~optional`<a id="tl::optional-T&-::~optional()"></a>

<pre><code class="language-cpp">~optional() = default;</code></pre>

No-op

### Assignment operator `tl::optional<T&>::operator=`<a id="tl::optional-T&-::operator=(tl::nullopt_t)"></a>

<pre><code class="language-cpp"><a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; operator=(<a href='doc_optional.html#tl::nullopt_t'>nullopt_t</a>) noexcept;</code></pre>

Assignment to empty.

Destroys the current value if there is one.

### Copy assignment operator `tl::optional<T&>::operator=`<a id="tl::optional-T&-::operator=(constoptional&)"></a>

<pre><code class="language-cpp"><a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; operator=(const <a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) = default;</code></pre>

Copy assignment.

Rebinds this optional to the referee of `rhs` if there is one. Otherwise resets the stored value in `*this`.

### Assignment operator `tl::optional<T&>::operator=`<a id="tl::optional-T&-::operator=(U&&)"></a>

<pre><code class="language-cpp">optional &amp;operator=(U &amp;&amp;u);</code></pre>

Rebinds this optional to `u`.

*Requires*: `U` must be an lvalue reference.

### Assignment operator `tl::optional<T&>::operator=`<a id="tl::optional-T&-::operator=(constoptional-U-&)"></a>

<pre><code class="language-cpp">template &lt;class U&gt;
<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; operator=(const <a href='doc_optional.html#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);</code></pre>

Converting copy assignment operator.

Rebinds this optional to the referee of `rhs` if there is one. Otherwise resets the stored value in `*this`.

### Function template `tl::optional<T&>::emplace`<a id="tl::optional-T&-::emplace(Args&&...)"></a>

<pre><code class="language-cpp">(1)  template &lt;class ... Args&gt;
     T&amp; emplace(Args&amp;&amp;... args) noexcept;</code></pre>

Constructs the value in-place, destroying the current one if there is one.

### Function `tl::optional<T&>::swap`<a id="tl::optional-T&-::swap(optional&)"></a>

<pre><code class="language-cpp">void swap(<a href='doc_optional.html#tl::optional-T-'>optional</a>&amp; rhs) noexcept;</code></pre>

Swaps this optional with the other.

If neither optionals have a value, nothing happens. If both have a value, the values are swapped. If one has a value, it is moved to the other and the movee is left valueless.

### Operator `tl::optional<T&>::operator->`<a id="tl::optional-T&-::operator--()const"></a>

<pre><code class="language-cpp">(1)  constexpr const T *operator-&gt;() const;

(2)  constexpr T *operator-&gt;();</code></pre>

*Returns*: a pointer to the stored value

*Requires*: a value is stored

### Operator `tl::optional<T&>::operator*`<a id="tl::optional-T&-::operator*()&"></a>

<pre><code class="language-cpp">(1)  constexpr T &amp;operator*();

(2)  constexpr const T &amp;operator*() const;</code></pre>

*Returns*: the stored value

*Requires*: a value is stored

### Function `tl::optional<T&>::has_value`<a id="tl::optional-T&-::has_value()const"></a>

<pre><code class="language-cpp">(1)  constexpr bool has_value() const noexcept;

(2)  constexpr operator bool() const noexcept;</code></pre>

*Returns*: whether or not the optional has a value

### Function `tl::optional<T&>::value`<a id="tl::optional-T&-::value()&"></a>

<pre><code class="language-cpp">(1)  constexpr T&amp; value() &amp;;

(2)  constexpr const T &amp;value() const;</code></pre>

*Returns*: the contained value if there is one, otherwise throws \[bad\_optional\_access\]

synopsis constexpr T \&value();

### Function template `tl::optional<T&>::value_or`<a id="tl::optional-T&-::value_or(U&&)const&"></a>

<pre><code class="language-cpp">(1)  template &lt;class U&gt;
     constexpr T value_or(U&amp;&amp; u) const &amp;;

(2)  template &lt;class U&gt;
     constexpr T value_or(U&amp;&amp; u) &amp;&amp;;</code></pre>

*Returns*: the stored value if there is one, otherwise returns `u`

### Function `tl::optional<T&>::reset`<a id="tl::optional-T&-::reset()"></a>

<pre><code class="language-cpp">void reset() noexcept;</code></pre>

Destroys the stored value if one exists, making the optional empty

-----

-----
