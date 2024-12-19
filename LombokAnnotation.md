# Lombok: Simplifying Java Development

Lombok is a Java library that can generate known patterns of code for us, allowing us to reduce the boilerplate code. In this article, we’ll walk through each of the 16 annotations provided by Lombok and quickly discuss how to use them.

---

## @NotNull
![NotNull Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*2KDNfqUWDKIj0CxweHo7BQ.png)

This annotation can be used to validate a constructor or a method parameter. Additionally, if we annotate a field with `@NonNull`, the validation will be added to the constructor and setter method. Let’s compare the plain-Java solution with Lombok’s `@NonNull`:



---

## @Getter & @Setter
Perhaps the most popular Lombok annotations, `@Getter` and `@Setter` can be used to automatically generate getters and setters for all the fields.

---
![Comparison](https://miro.medium.com/v2/resize:fit:828/format:webp/1*PjhVgJUS0BQr6nXAC-sPBA.png)

## @ToString
This annotation is going to override the `toString()` method for easy debugging. As a result, the current state of the object will be returned as a string when `toString()` is called.

![ToString Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*4BHPriFmNGp7clGp5CGvng.png)

---

## @EqualsAndHashCode
If we need to override the `equals` method of a class and compare the fields instead of the reference, we can do it by adding the `@EqualsAndHashCode` annotation. This will also override the `hashcode()` method accordingly.

![EqualsAndHashCode Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*HUwktJFiNoM1KNizjkZHpQ.png)

---

## @NoArgsConstructor & @AllArgsConstructor
We can easily generate the class constructors with Lombok. 
- `@AllArgsConstructor`: Creates a constructor with all fields.
- `@NoArgsConstructor`: Creates a default constructor with no arguments.

---
![Value Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*smkfbGQhJ-GALZ_c49aeCQ.png)

## @RequiredArgsConstructor
For classes with `final` fields, use `@RequiredArgsConstructor` to generate a constructor for those fields only.
---
![Value Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*hsi4AaRfy2GxThdLSA1WVA.png)

## @Data
`@Data` is a combination of:
- `@Getter`
- `@Setter`
- `@ToString`
- `@EqualsAndHashCode`
![Value Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*lM-wqdngHYb_dmbDGz9n6A.png)
It generates all the boilerplate code required to expose the fields of a class.

---

## @Value
For immutable classes, use `@Value`. It makes fields `private` and `final`, and generates an all-arguments constructor, along with `toString()`, `hashcode()`, and `equals()` methods.

![Value Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*mUi_Q53QwpOgNZqgZD6uEg.png)

---

## @Builder
The `@Builder` annotation injects an implementation of the builder design pattern, especially useful for classes with many fields.

![Builder Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*w8hNyjOS-tTRPmNMNznk7Q.png)

---

## @SneakyThrows
The `@SneakyThrows` annotation surrounds the code with a try-catch block and wraps checked exceptions in a `RuntimeException`.

![SneakyThrows Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*Ea8xOVd--bJSmBfO9MjTPg.png)

---

## @Synchronized
For safer synchronized method calls, replace the Java `synchronized` keyword with `@Synchronized`.

![Synchronized Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*BJDogk8E01zwQ1_EYriPtg.png)

---

## @With
For immutable classes, `@With` generates a method that returns a new instance of the object with one of its fields updated.

![With Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*WFtEBOMcTA9YLBvHIFLM_w.png)

---

## @Log
Add `@Slf4j`, `@Log4j2`, or other log annotations to automatically generate a logger instance in your class.

![Log Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*TP06WUavNkmIqjRpX6jlsw.png)

---

## @Cleanup
The `@Cleanup` annotation works with classes implementing the `Closable` interface. It ensures proper resource cleanup, similar to the try-with-resources block.

![Cleanup Example](https://miro.medium.com/v2/resize:fit:828/format:webp/1*Yh2NrdkjZyeLMIzrR__xpw.png)

---

## Conclusion
Lombok is a powerful tool that reduces boilerplate code, but with great power comes great responsibility.

> **"With great power comes great responsibility" — Peter Clark**

Overusing Lombok annotations like `@Data` or `@Getter` can lead to code clutter. Stay tuned for more articles on the pragmatic and responsible usage of Lombok!

---

Photo by [Tim van der Kuip](https://unsplash.com/@timvdk) on Unsplash.

**Thank You!**
