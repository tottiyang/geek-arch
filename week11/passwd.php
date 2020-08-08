<?php

/*
自PHP5.5.0之后，新增加了密码散列算法函数（password_hash），password_hash() 使用足够强度的单向散列算法创建密码的散列（hash）。 
password_hash() 兼容 crypt()。 所以， crypt() 创建的密码散列也可用于 password_hash()。
password_hash不需要再单独存储盐值，而且每次加密的值都不一样，我们只需要存储加密字符串，验证时用password_verify()方法即可得出结果！

当前支持的算法：
PASSWORD_DEFAULT - 使用 bcrypt 算法 (PHP 5.5.0 默认)。 注意，该常量会随着 PHP 加入更新更高强度的算法而改变。 
    所以，使用此常量生成结果的长度将在未来有变化。 因此，数据库里储存结果的列可超过60个字符（最好是255个字符）。
PASSWORD_BCRYPT - 使用 CRYPT_BLOWFISH 算法创建散列。 这会产生兼容使用 "$2y$" 的 crypt()。 
    结果将会是 60 个字符的字符串， 或者在失败时返回 FALSE。
PASSWORD_ARGON2I - 使用 Argon2 散列算法创建散列。

返回值：

返回散列后的密码， 或者在失败时返回 FALSE。
使用的算法、cost 和盐值作为散列的一部分返回。所以验证散列值的所有信息都已经包含在内。 
这使 password_verify() 函数验证的时候，不需要额外储存盐值或者算法的信息。
 */

/**
 * 加密
 * 
 * 我们想要使用默认算法散列密码
 * 当前是 BCRYPT，并会产生 60 个字符的结果。
 *
 * 请注意，随时间推移，默认算法可能会有变化，
 * 所以需要储存的空间能够超过 60 字（255字不错）
 * 
 * 输出类似结果：
 * $2y$10$.vGA1O9wmRjrwAVXD98HNOgsNpDczlqm3Jq7KnEd1rVAGv3Fykk1a 
 */
password_hash("rasmuslerdorf", PASSWORD_DEFAULT);

/**
 * 验证
 * 
 * 输出：True  或 False
 */
$inputValue = '123456'; //用户输入的密码
password_verify( $inputValue, '存储的加密字符串');

?>

