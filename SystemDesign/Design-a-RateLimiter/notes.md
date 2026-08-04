# Rate Limiting in System Design (Complete Deep Dive)

# Table of Contents

1. Introduction
2. Why Rate Limiting Exists
3. Real World Examples
4. Where Rate Limiting is Used
5. Types of Rate Limiting
6. Key Terminologies
7. Algorithms
    - Fixed Window Counter
    - Sliding Window Log
    - Sliding Window Counter
    - Token Bucket
    - Leaky Bucket
8. Distributed Rate Limiting
9. Redis Implementation
10. API Gateway Rate Limiting
11. Database Design
12. Scaling Challenges
13. Consistency Problems
14. Handling Multiple Servers
15. Interview Design
16. Example Architecture
17. Production Best Practices
18. Comparison Table
19. Interview Questions
20. Summary

---

# 1. Introduction

Rate limiting is a mechanism used to control how many requests a client can make in a certain period of time.

Think of it as a security guard standing outside a club.

Example:

Maximum allowed:
100 requests/minute

If the user sends

```
90 requests
```

Everything is fine.

If the user sends

```
150 requests
```

The last 50 requests are rejected.

Usually with

```
HTTP 429
Too Many Requests
```

---

# 2. Why Rate Limiting Exists

Without rate limiting:

```
User
   |
100000 Requests
   |
Server
   |
CPU 100%
Memory Full
Database Crashes
```

With rate limiting

```
User
 |
100000 Requests

↓

Only 100 Allowed

↓

Server remains healthy
```

Benefits

- Prevent DDoS
- Prevent brute force attacks
- Prevent API abuse
- Fair resource allocation
- Reduce infrastructure cost
- Improve availability

---

# 3. Real World Examples

## GitHub

5000 requests/hour

---

## Twitter API

Different limits for

- Tweets
- Likes
- Search
- Upload

---

## Google Maps API

Limit based on

- Requests/day
- Billing

---

## AWS API Gateway

Throttle

Example

```
100 requests/sec

Burst = 200
```

---

# 4. Where Rate Limiting is Used

- Login API
- Payment APIs
- Search APIs
- OTP APIs
- SMS Sending
- Password Reset
- Public REST APIs
- GraphQL APIs

---

# 5. Key Terminologies

## Limit

Maximum requests allowed

Example

100/min

---

## Window

Time interval

Examples

```
1 sec
1 min
1 hour
1 day
```

---

## Burst

Temporary spike allowed.

Example

Normal

```
100/sec
```

Burst

```
200/sec
```

---

## Quota

Long-term limit.

Example

```
1 million/month
```

---

# 6. Algorithms

---

# Fixed Window Counter

Idea

Maintain one counter.

```
Window = 1 minute

Counter

0

↓

1

↓

2

↓

100

↓

Reject
```

Example

```
10:00-10:01

100 requests

Allowed

10:01

Counter resets
```

Advantages

- Very simple
- Fast
- Low memory

Disadvantages

Boundary problem

Example

```
10:00:59

100 requests

10:01:01

100 requests

Total

200 requests in 2 seconds
```

---

# Sliding Window Log

Store every request timestamp.

Example

```
10:00:01

10:00:05

10:00:10

10:00:15
```

When a request comes

Delete timestamps older than 1 minute.

Count remaining timestamps.

Advantages

Very accurate.

Disadvantages

High memory usage.

Complexity

Memory

O(n)

---

# Sliding Window Counter

Combination of

- Fixed Window
- Sliding Window

Stores

Current window

Previous window

Calculates weighted average.

Advantages

Less memory.

Good accuracy.

Used in production.

---

# Token Bucket

Most popular algorithm.

Imagine a bucket.

```
Capacity

10 tokens
```

Every second

```
+1 token
```

Each request

Consumes

```
1 token
```

Example

Bucket

```
10

↓

9

↓

8

↓

7
```

No token?

Reject request.

Advantages

Supports bursts.

Widely used.

Examples

- AWS
- Stripe
- NGINX

---

# Leaky Bucket

Imagine water leaking from bucket.

Incoming

```
||||||||||
```

Outgoing

```
|
|
|
|
```

Constant speed.

Advantages

Smooth traffic.

Disadvantages

Cannot handle large bursts.

---

# 7. Comparison

| Algorithm | Memory | Accuracy | Burst |
|------------|---------|----------|-------|
| Fixed Window | Low | Low | Poor |
| Sliding Log | High | Excellent | Good |
| Sliding Counter | Medium | Good | Good |
| Token Bucket | Low | Excellent | Excellent |
| Leaky Bucket | Low | Good | Poor |

---

# 8. Distributed Rate Limiting

Suppose

```
5 servers
```

```
          Load Balancer
          /  |  \
         /   |   \
       S1   S2   S3
       |     |    |
```

Problem

Each server has its own counter.

User sends

```
100 requests

Randomly distributed

S1 = 30

S2 = 30

S3 = 40
```

Each thinks user is below limit.

Actually

Total

100+

Need centralized storage.

Usually

Redis.

---

# 9. Why Redis?

Redis offers

- Extremely fast
- In-memory
- Atomic operations
- Expiration (TTL)
- Distributed

Example

```
Key

user123

Value

67
```

Increment

```
INCR user123
```

Set expiry

```
EXPIRE user123 60
```

Perfect for rate limiting.

---

# 10. Redis Example

User

```
123
```

Key

```
rate_limit:user123
```

Value

```
45
```

TTL

```
60 seconds
```

Flow

Request

↓

INCR

↓

Count

↓

<100 ?

↓

Allow

Else

Reject

---

# 11. API Gateway

Often rate limiting happens before backend.

```
Client

↓

API Gateway

↓

Authentication

↓

Rate Limiter

↓

Backend
```

Examples

- Kong
- NGINX
- Envoy
- AWS API Gateway

---

# 12. Database Design

Normally

```
Key

userId:endpoint
```

Example

```
123:/login
```

Or

```
IP Address

192.168.x.x
```

Or

API Key

```
sk_live_xxxxx
```

---

# 13. Scaling Challenges

Millions of users.

Need

- Horizontal scaling
- Shared state
- Fast lookups
- Atomic increment
- Low latency

Redis Cluster solves this.

---

# 14. Consistency Problems

Two servers

Both increment simultaneously.

Need

Atomic operations.

Redis

```
INCR
```

is atomic.

No race condition.

---

# 15. Multi-Level Rate Limiting

Can apply limits on

- User
- IP
- API Key
- Endpoint
- Organization
- Country

Example

```
100/min/user

1000/min/IP

5000/min/API Key
```

---

# 16. Interview Design

Question

Design a Rate Limiter for Twitter.

Architecture

```
Client

↓

Load Balancer

↓

API Gateway

↓

Authentication

↓

Redis Rate Limiter

↓

Application Servers

↓

Database
```

Steps

1. Receive request
2. Authenticate
3. Build rate-limit key
4. Check Redis
5. Increment counter
6. Allow or Reject
7. Return HTTP 429 if exceeded

---

# 17. Production Best Practices

Use

- Redis Cluster
- Token Bucket
- Expiring Keys
- Atomic Operations
- Monitoring
- Metrics
- Logging
- Retry headers

Headers

```
X-RateLimit-Limit

X-RateLimit-Remaining

X-RateLimit-Reset

Retry-After
```

---

# 18. Common Interview Questions

Q1. Why Redis?

Answer

Fast in-memory storage with atomic increments.

---

Q2. Why Token Bucket?

Supports burst traffic while enforcing average rate.

---

Q3. Why not Database?

Too slow.

High write load.

---

Q4. Why Sliding Window?

More accurate than Fixed Window.

---

Q5. What happens if Redis crashes?

Solutions

- Redis replication
- Redis Sentinel
- Redis Cluster
- Fallback local cache

---

# 19. Advantages

- Prevent abuse
- Protect infrastructure
- Reduce costs
- Fair usage
- Improve reliability
- Better security

---

# 20. Disadvantages

- Additional infrastructure
- Distributed synchronization
- Redis dependency
- Clock synchronization issues
- Slight latency increase

---

# Final Summary

A production-grade rate limiter typically uses:

- API Gateway for enforcement
- Redis for distributed counters
- Token Bucket or Sliding Window algorithms
- HTTP 429 responses for exceeded limits
- Monitoring, metrics, and alerting for observability

Choosing the right algorithm depends on your goals:
- **Fixed Window**: Simple but inaccurate near window boundaries.
- **Sliding Window**: Accurate but more complex.
- **Token Bucket**: Best general-purpose choice; supports bursts and is widely adopted.
- **Leaky Bucket**: Best when a constant output rate is required.