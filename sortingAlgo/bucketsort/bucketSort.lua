local function bucketSort(t)
    local n = #t
    local buckets = {}
    for i = 1, n do
        local bucket = math.floor(n * t[i])
        buckets[bucket] = buckets[bucket] or {}
        table.insert(buckets[bucket], t[i])
    end
    for i = 1, n do
        if buckets[i] then
            table.sort(buckets[i])
        end
    end
    local k = 1
    for i = 1, n do
        if buckets[i] then
            for j = 1, #buckets[i] do
                t[k] = buckets[i][j]
                k = k + 1
            end
        end
    end
end

local t = { 0.3, 0.2, 0.1, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1 }
bucketSort(t)
print(table.concat(t, ", "))